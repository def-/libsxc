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

#ifndef LIBSXC_OPTION_EXCEPTION_CONFLICT_HXX
#define LIBSXC_OPTION_EXCEPTION_CONFLICT_HXX

// INCLUDE/*{{{*/

#include <exception>

#include <libsxc/Exception/Exception.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    namespace Exception
    {
      /**
       * @brief An exception to be thrown when options are conflicting.
       *
       * Options can conflict if either an option has been set too often or if
       * two options are mutual exclusive.
       */
      class Conflict : virtual public libsxc::Exception::Exception
      {
        public:
          Conflict(const char* name) throw();
          Conflict(const char* name, const std::exception& cause) throw();
        private:
          void _createMessage(const char* name) throw();
      };
    }
  }
}

#endif // LIBSXC_OPTION_EXCEPTION_CONFLICT_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
