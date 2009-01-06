// LICENSE/*{{{*/
/*
  sxc - Simple Xmpp Client
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

#ifndef LIBSXC_SIGNAL_WAITER_HXX
#define LIBSXC_SIGNAL_WAITER_HXX

// INCLUDES/*{{{*/

#include <map>
#include <pthread.h>

#include <libsxc/Signal/Handler.hxx>

/*}}}*/

namespace libsxc
{
  namespace Signal
  {
    typedef std::map<unsigned int, Handler *> Handlers;

    /**
     * Wait for signals and redirect them to registered handlers. Even if no
     * handler is registered, the signals will be caught and ignored instead of
     * running the default action. You can disable this behaviour in the
     * constructor to only catch the signals that have a handler registered.
     *
     * @note Create an object before you start any thread, so the sigmask is
     *       the same everywhere. If you set the behaviour to leave the default
     *       handling for some signals, register all handlers before you start
     *       any other thread. You can still run the @ref run method after
     *       creating the threads.
     */
    class Waiter
    {
      public:
        //Waiter();/*{{{*/

        /**
         * Initialize all the variables with empty values. Don't do any real
         * work.
         *
         * @param fill Whether to fill the sigmask with all signals or leave it
         *        empty.
         */
        Waiter(bool fill = true);

    /*}}}*/
        //~Waiter();/*{{{*/

        /**
         * Make the waiter thread exit if it is running and delete all
         * registered signal handlers.
         */
        ~Waiter();

    /*}}}*/

        //void reg(unsigned int signal, Handler &sh);/*{{{*/

        /**
         * Register a @ref Handler to a signal. Can be called multiple times
         * with different signals to register a handler to more than one
         * signal.  Registering for a signal twice will not work. Registering
         * while the signal waiter is running will also fail.
         *
         * @param signal The signal to register with.
         * @param sh The signal handler to register. Passes ownership.
         */
        void reg(unsigned int signal, Handler &sh);

    /*}}}*/
        //void run();/*{{{*/

        /**
         * Start waiting for registered signals and redirecting them to their
         * assigned handlers. This won't work if you have no @ref Handler
         * registered. Returns immediately if a stop was already requested
         * using @ref stop. This method does not block, using @ref join for
         * this.
         */
        void run();

/*}}}*/
        //void join();/*{{{*/

        /**
         * Use this method after running the waiter using @ref run if you want
         * to block. This method will return after the thread created by @ref
         * run returns.
         */
        void join();

/*}}}*/
        //void stop();/*{{{*/

        /**
         * Stop a running signal waiting thread and, if available, make the
         * blocking @ref run method return. Calling this method without having
         * called @ref run is allowed, but has no effect.
         */
        void stop();

    /*}}}*/

      private:
        //static void *_wait(void *rawThat);/*{{{*/

        /**
         * The actual worker method that does the signal waiting and directing
         * to the appropriate handler.
         *
         * @param rawThat "this" has to be passed, as this is a static class
         *        method, so it works with pthreads.
         */
        static void *_wait(void *rawThat);

    /*}}}*/

        //sigset_t _set;/*{{{*/

        /// The signals to be handled.
        sigset_t _set;

    /*}}}*/
        //Handlers _handlers;/*{{{*/

        /// The handlers for the signals.
        Handlers _handlers;

    /*}}}*/
        //pthread_t _threadId;/*{{{*/

        /**
         * The thread id of the signal waiting thread. Only useful if @ref
         * _running.
         */
        pthread_t _threadId;

    /*}}}*/
        //volatile bool _stopRequested;/*{{{*/

        /// Whether the signal waiting thread should be immediately stopped.
        volatile bool _stopRequested;

    /*}}}*/
        //volatile bool _running;/*{{{*/

        /// Whether the signal waiting thread is running at the moment.
        volatile bool _running;

    /*}}}*/
    };
  }
}

#endif // LIBSXC_SIGNAL_WAITER_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
