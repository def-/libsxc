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

#ifndef LIBSXC_EXCEPTION_RUNTIMEERROR_HXX
#define LIBSXC_EXCEPTION_RUNTIMEERROR_HXX

// INCLUDE/*{{{*/

#include <libsxc/Exception/Exception.hxx>

#include <exception>

/*}}}*/

namespace libsxc
{
  namespace Exception
  {
    /**
     * @brief Base class for errors that could only be detected at runtime.
     */
    class RuntimeError : virtual public Exception
    {
      public:
        // RuntimeError(const char* message) throw();/*{{{*/

        /**
         * @brief Default constructor.
         *
         * @param message C-string describing the error.
         */
        RuntimeError(const char* message) throw();

/*}}}*/
        // RuntimeError(const char*, const std::exception&) throw();/*{{{*/

        /**
         * @brief Extended default constructor using a backtrace.
         *
         * @param message C-string describing the error.
         * @param cause The cause for the throwing of this exception.
         */
        RuntimeError(const char* message, const std::exception& cause) throw();

/*}}}*/
        // virtual ~RuntimeError() throw()/*{{{*/

        /**
         * @brief Virtual destructor.
         */
        virtual ~RuntimeError() throw();

/*}}}*/

      protected:
        // RuntimeError() throw();/*{{{*/

        /**
         * @see libsxc::RuntimeError::RuntimeError::RuntimeError()
         */
        RuntimeError() throw();

/*}}}*/
        // RuntimeError(const std::exception& cause) throw();/*{{{*/

        /**
         * @see libsxc::RuntimeError::RuntimeError::RuntimeError(const std::exception&)
         */
        RuntimeError(const std::exception& cause) throw();

/*}}}*/
    };
  }
}

#endif // LIBSXC_EXCEPTION_RUNTIMEERROR_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
