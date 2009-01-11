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


#ifndef LIBSXC_SIGNAL_HANDLER_HXX
#define LIBSXC_SIGNAL_HANDLER_HXX

namespace libsxc
{
  namespace Signal
  {
    /**
     * Handle operating system signals that reach the program.
     *
     * @note See the @ref Waiter for how to register signal handlers.
     */
    class Handler
    {
      public:
        virtual ~Handler() {}
        //virtual void handle(unsigned int signal) = 0;/*{{{*/

        /**
         * Handle a signal.
         * @param signal The signal number. See the documentation of your
         *        operating system for information about existing signals.
         */
        virtual void handle(unsigned int signal) = 0;

/*}}}*/
    };
  }
}

#endif // LIBSXC_SIGNAL_HANDLER_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
