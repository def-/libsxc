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



#ifndef EXCEPTION_OPTIONEXCEPTION_HXX
#define EXCEPTION_OPTIONEXCEPTION_HXX


// INCLUDE/*{{{*/

#include <string>

#include <libsxc/Exception/Exception.hxx>

/*}}}*/

namespace libsxc
{
  namespace Exception
  {
    /**
     * @brief A class for program argument exceptions.
     */
    class OptionException : public Exception
    {
      public:
        //OptionException(Type type, std::string message="");/*{{{*/

        /**
         * @brief Create a gloox exception object.
         *
         * @param type The type of the exception.
         * @param message A text describing the exception more verbose.
         */
        OptionException(Type type, std::string message="");

  /*}}}*/
        //void createDescription() throw();/*{{{*/

        /**
         * @brief Create the description text.
         */
        void createDescription() throw();

  /*}}}*/
    };
  }
}

#endif // EXCEPTION_GLOOXEXCEPTION_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
