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


// INCLUDE/*{{{*/

#include <string>

#include <libsxc/Exception/GlooxException.hxx>

/*}}}*/


namespace libsxc
{
  namespace Exception
  {
    GlooxException::GlooxException(Type type, std::string message)/*{{{*/
    : Exception(type, message)
    {
    }/*}}}*/

    void GlooxException::createDescription() throw()/*{{{*/
    {
      switch (_type) {
        case Connection:
          _description = "Connection error: " + _message;
          break;
        case Registration:
          _description = "Registration error: " + _message;
          break;
        case PrivacyList:
          _description = "Privacy list error: " + _message;
          break;
        case SessionCreate:
          _description = "Session establishment error: " + _message;
          break;
        case Stanza:
          _description = "Stanza error: " + _message;
          break;
        case Stream:
          _description = "Stream error: " + _message;
          break;
        default:
          setInvalid();
      }
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
