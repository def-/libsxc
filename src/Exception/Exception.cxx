#line 1 "libsxc:Exception/Exception.cxx"
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


// INCLUDE/*{{{*/

#include <string>

#include <libsxc/Exception/Exception.hxx>
#include <libsxc/Exception/Type.hxx>

/*}}}*/

namespace libsxc
{
  namespace Exception
  {
    Exception::Exception(Type type, std::string &message) throw()/*{{{*/
    : _type(type), _message(message), _isDescriptionCreated(false)
    {
    }/*}}}*/
    Exception::Exception(Type type, const char *message) throw()/*{{{*/
    : _type(type), _isDescriptionCreated(false)
    {
      _message = *message;
    }/*}}}*/

    Exception::~Exception() throw()/*{{{*/
    {
    }/*}}}*/
    const char *Exception::what() const throw()/*{{{*/
    {
      return getMessage().c_str();
    }/*}}}*/

    const std::string &Exception::getMessage() const throw()/*{{{*/
    {
      return _message;
    }/*}}}*/
    const std::string &Exception::getDescription() throw()/*{{{*/
    {
      if (!_isDescriptionCreated) {
        createDescription();
        _isDescriptionCreated = true;
      }
      return _description;
    }/*}}}*/
    Type Exception::getType() const throw()/*{{{*/
    {
      return _type;
    }/*}}}*/

    void Exception::setInvalid() throw()/*{{{*/
    {
      _description = "Invalid exception type.";
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
