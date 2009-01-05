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

#ifndef LIBSXC_SIGNAL_STOPON_HXX
#define LIBSXC_SIGNAL_STOPON_HXX

// INCLUDES/*{{{*/
#include <libsxc/Signal/Handler.hxx>
#include <libsxc/Signal/Waiter.hxx>
/*}}}*/

namespace libsxc
{
  namespace Signal
  {
    /**
     * A @ref Handler that stops the @ref Waiter when receiving a signal.
     */
    class Stopper : public Handler
    {
      public:
        Stopper(Waiter &waiter);
        //void handle(unsigned int signal) {}/*{{{*/

        /**
         * Stop the waiter when a signal comes in.
         */
        void handle(unsigned int signal);

/*}}}*/
      protected:
        void stop();
      private:
        Waiter &_waiter;
    };

    //void ignore(Waiter &sw, unsigned int signal);/*{{{*/

    /**
     * Register a handler to stop the waiter when the signal is received.
     *
     * @param sw The @ref Waiter to operate on and to give to the @ref Handler.
     * @param signal The signal to stop on.
     */
    void stopOn(Waiter &sw, unsigned int signal);

/*}}}*/
  }
}

#endif // LIBSXC_SIGNAL_STOPON_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
