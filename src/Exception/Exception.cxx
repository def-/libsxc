#line 2 "libsxc:Exception/Exception.cxx"
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

#include <libsxc/Exception/Exception.hxx>
#include <libsxc/Exception/Type.hxx>

#include <cstring>
#include <exception>

/*}}}*/

namespace libsxc
{
  namespace Exception
  {
    Exception::Exception(const char* message, Type type) throw()/*{{{*/
    : _type(type)
    {
      setMessage(message);
      _cause[0] = '\0';
      _what[0]  = '\0';

      createBacktrace();
    }

/*}}}*/
    Exception::Exception(/*{{{*/
      const char* message, Type type, const std::exception& cause) throw()
    : _type(type)
    {
      setMessage(message);
      _setCause(cause.what());
      _what[0] = '\0';

      createBacktrace();
    }

/*}}}*/
    Exception::~Exception() throw()/*{{{*/
    {
    }

/*}}}*/
    const char* Exception::what() const throw()/*{{{*/
    {
      return _what;
    }

/*}}}*/
    const char* Exception::getMessage() const throw()/*{{{*/
    {
      return _message;
    }

/*}}}*/
    Type Exception::getType() const throw()/*{{{*/
    {
      return _type;
    }

/*}}}*/
    const char* Exception::getCause() const throw()/*{{{*/
    {
      return _cause;
    }

/*}}}*/

    Exception::Exception() throw()/*{{{*/
    : _type(General)
    {
      _message[0] = '\0';
      _cause[0]   = '\0';
      _what[0]    = '\0';
    }

/*}}}*/
    Exception::Exception(const std::exception& cause) throw()/*{{{*/
    : _type(General)
    {
      _message[0] = '\0';
      _setCause(cause.what());
      _what[0]    = '\0';
    }

/*}}}*/
    void Exception::createBacktrace() throw()/*{{{*/
    {
      if ('\0' != _what[0])
        return;

      strcpy(_what, _cause);
      strcat(_what, _message);
    }

/*}}}*/
    void Exception::setMessage(const char* message) throw()/*{{{*/
    {
      strncpy(_message, message, MESSAGE_BUFFER_SIZE - 1);
      // The message supplied may be longer than the buffers size. strncopy()
      // will neither write beyond the bounds, nor will it append a trailing
      // null character if the source contains too much characters. Terminate
      // cstring manually so that we do not end up using a string which is not
      // terminated by null.
      _message[MESSAGE_BUFFER_SIZE - 1] = '\0';

      // Make sure _message ends with a newline.
      const size_t length = strlen(_message);
      if ('\n' == _message[length - 1])
        return;
      if ((MESSAGE_BUFFER_SIZE - 1) > length) {
        // Enough space left to increase length of string by appending one
        // newline.
        _message[length + 1] = '\0';
        _message[length]     = '\n';
      } else {
        // Not enough space left, overwrite last char. String has most likely
        // already been truncated.
        _message[length - 1] = '\n';
      }
    }

/*}}}*/
    void Exception::setType(Type type) throw()/*{{{*/
    {
      _type = type;
    }

/*}}}*/

    void Exception::_setCause(const char* cause) throw()/*{{{*/
    {
      // See setMessage() for explanation.

      strncpy(_cause, cause, CAUSE_BUFFER_SIZE - 1);
      _cause[CAUSE_BUFFER_SIZE - 1] = '\0';

      const size_t length = strlen(_cause);
      if ('\n' == _cause[length - 1])
        return;
      if ((CAUSE_BUFFER_SIZE - 1) > length) {
        _cause[length + 1] = '\0';
        _cause[length]     = '\n';
      } else {
        _cause[length - 1] = '\n';
      }
    }

/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
