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

#ifndef LIBSXC_DEBUG_OUTPUT_HXX
#define LIBSXC_DEBUG_OUTPUT_HXX

// INCLUDE/*{{{*/


/*}}}*/

namespace libsxc
{
  namespace Debug
  {
    /**
     * This is an implementation of the OutputPolicy of @ref Logger.
     */
    class Output
    {
      public:
        virtual ~Output() {}
      protected:
        //void print(const std::string &text);/*{{{*/

        /**
         * Print a text that has been formatted to stderr.
         *
         * @param text The formatted text.
         */
        void print(const std::string &text);

/*}}}*/
    };
  }
}

#endif // LIBSXC_DEBUG_OUTPUT_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
