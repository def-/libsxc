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
#ifndef LIBSXC_EXIT_CODE_HXX
#define LIBSXC_EXIT_CODE_HXX

namespace libsxc
{
  namespace Exit
  {
    /**
     * @brief An enum for exit codes.
     *
     * Developers and users of exception classes are free to use any of them.
     * The exit codes do not depend on specific exception classes.
     */
    enum Code
    {
      // Generic errors:/*{{{*/
      NoError          =   0, // No problem occured.
      General          =  64,
/*}}}*/
      // Program option exceptions./*{{{*/
      MissingOption    =  80,
      MissingValue     =  81,
      UnknownOption    =  82,
      InvalidValue     =  83,
      Conflict         =  84,
/*}}}*/
    };
  }
}

#endif // LIBSXC_EXIT_CODE_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
