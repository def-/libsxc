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

#ifndef LIBSXC_DEBUG_FORMAT_HXX
#define LIBSXC_DEBUG_FORMAT_HXX

// INCLUDE/*{{{*/


/*}}}*/

namespace libsxc
{
  namespace Debug
  {
    /**
     * This is an implementation of the FormatPolicy of @ref Logger.
     */
    class Format
    {
      public:
        virtual ~Format() {}
      protected:
        //const string format(file, line, &raw);/*{{{*/

        /**
         * Format a string to be printed.
         *
         * @param file The name of the current file.
         * @param line The number of the current line.
         * @param raw The raw text to be formatted
         * @return The formatted text.
         */
        const std::string format(
          const std::string file,
          unsigned int line,
          const std::string &raw);

  /*}}}*/
    };
  }
}

#endif // LIBSXC_DEBUG_FORMAT_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
