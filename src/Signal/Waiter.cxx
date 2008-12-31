#line 1 "libsxc:Signal/Waiter.cxx"
// LICENSE/*{{{*/
/*
  libsxc
  Copyright (C) 2008 Dennis Felsing, Andreas Waidler

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*}}}*/

// INCLUDE/*{{{*/

#include <map>

#include <pthread.h>
#include <signal.h>
#include <errno.h>

#include <libsxc/Signal/Waiter.hxx>

/*}}}*/

namespace libsxc
{
  namespace Signal
  {
    Waiter::Waiter(bool fill)/*{{{*/
    : _handlers()
    , _set()
    , _threadId()
    , _stopRequested(false)
    , _running(false)
    {
      if (fill) {
        // Fill with all signals.
        if (sigfillset(&_set))
          return;
      } else {
        // Clear the signal selection.
        if (sigemptyset(&_set))
          return;
      }
      // Publish the sigmask.
      int status = pthread_sigmask(SIG_SETMASK, &_set, NULL);
      if (status)
        return;
    }/*}}}*/

    Waiter::~Waiter()/*{{{*/
    {
      if (_running) {
        stop();
        int status = pthread_join(_threadId, NULL);
        if (status)
          return;
      }

      for (
      Handlers::iterator handler = _handlers.begin();
      handler != _handlers.end();
      ++handler) {
        delete handler->second;
      }
    }/*}}}*/

    void Waiter::reg(unsigned int signal, Handler &sh)/*{{{*/
    {
      if (_handlers.end() != _handlers.find(signal)) {
        // There already is a signal handler registered for this signal.
        // FIXME: throw appropriate exception
        return;
      }
      if (_running) {
        // Don't register signal handlers while running, as they would be added
        // _after_ the next signal has been received.
        // FIXME: throw appropriate exception
        return;
      }
      if (sigaddset(&_set, signal))
        return;
      _handlers.insert(std::make_pair(signal, &sh));

      int status = pthread_sigmask(SIG_SETMASK, &_set, NULL);
      if (status)
        return;
    }/*}}}*/

    void Waiter::stop()/*{{{*/
    {
      if (!_running)
        // Allow this method without having the thread actually running.
        return;

      _stopRequested = true;

      // Send a signal to the current process that will be caught by the
      // running @ref wait thread and result in the thread to exit. Not using
      // _threadId or raise(), as they are thread specific.
      unsigned int signal;
      if (_handlers.empty()) {
        signal = SIGINT;
      } else {
        signal = _handlers.begin()->first;
      }
      if (-1 == kill(getpid(), signal)) {
        int err = errno;
        return;
      }
    }/*}}}*/

    void Waiter::run(bool blocking)/*{{{*/
    {
      if (_handlers.empty() && !sigismember(&_set, SIGINT)) {
        // We need at least one signal handler registered, or all signals set
        // to ignore, so we can send it in case we want to stop the thread.
        // FIXME: throw appropriate exception
        return;
      }

      int status;

      status = pthread_create(&_threadId, NULL, _wait, (void *) this);
      if (status)
        return;

      if (blocking) {
        status = pthread_join(_threadId, NULL);
        if (status)
          return;
      }
    }/*}}}*/

    void *Waiter::_wait(void *rawThat)/*{{{*/
    {
      Waiter *that = reinterpret_cast<Waiter *>(rawThat);
      that->_running = true;
      int number;
      int count = 0;
      Handlers::iterator handler;
      int status;

      while (true) {
        status = sigwait(&(that->_set), &number);
        if (status)
          return (void *) NULL;

        if (that->_stopRequested) {
          // Don't call the handler as we have to exit immediately. The
          // received signal is most probably the one sent by the @ref stop
          // method, but this doesn't matter, and does not have to be proven,
          // as we have to exit anyway without handling anything else (even the
          // signals already in queue).
          return (void *) NULL;
        }

        handler = that->_handlers.find(number);
        if (that->_handlers.end() != handler)
          handler->second->handle(number);
        // else: ignore.
      }

      that->_running = false;
      return (void *) NULL;
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
