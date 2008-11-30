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

#ifndef ERROR_HANDLER_HXX
#define ERROR_HANDLER_HXX

// INCLUDE/*{{{*/

/*}}}*/

namespace libsxc
{
  namespace Error
  {
    /**
     * Error handling interface.
     */
    class Handler
    {
      public:
        //virtual void listen(const std::string &message) = 0;/*{{{*/

        /**
         * This method is called to listen to an error message.
         *
         * @ref message The message to listen to.
         */
        virtual void listen(const std::string &message) = 0;

/*}}}*/
        //virtual void listenCritical(const std::string &message) = 0;/*{{{*/

        /**
         * This method listens to the messages of critical errors.
         *
         * @ref message The message to listen to.
         */
        virtual void listenCritical(const std::string &message) = 0;

/*}}}*/
        //virtual void terminate(int exitCode) = 0;/*{{{*/

        /**
         * Call this method when something is broken and therefore the program
         * has to stop execution.
         *
         * @param exitCode The exit code to return when exiting the program.
         */
        virtual void terminate(int exitCode) = 0;

/*}}}*/
    };
  }
}

#endif // ERROR_HANDLER_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
