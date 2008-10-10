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


// INCLUDES/*{{{*/

#include <string>

#include <libsxc/Option/OptionPort.hxx>
#include <libsxc/Exception/OptionException.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    OptionPort::OptionPort(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string variable,
      std::string description)
    : Option<int>::Option(
      parser,
      shortName,
      longName,
      variable,
      description,
      -1)
    {
    }/*}}}*/

    void OptionPort::setValue(std::string rawValue)/*{{{*/
    {
      Option<int>::setValue(rawValue);

      if (getValue() < -1 || getValue() > 65535)
        throw Exception::OptionException(
          Exception::PortInvalid,
          rawValue);
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
