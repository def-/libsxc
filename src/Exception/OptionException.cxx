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

#include <libsxc/Exception/OptionException.hxx>

#ifdef HAVE_CONFIG_H
#   include <config.hxx>
#endif

/*}}}*/


namespace libsxc
{
    namespace Exception
    {
        OptionException::OptionException(Type type, std::string message)/*{{{*/
        : Exception(type, message)
        {
        }/*}}}*/

        void OptionException::createDescription() throw()/*{{{*/
        {
            switch (_type) {
                case ShowUsage:
                    _description = "";
                    break;
                case OptionNotSet:
                    _description =
                    "Obligatory option " + _message + " not set";
                    break;
                case OptionUnknown:
                    _description = "Unknown option " + _message;
                    break;
                case ValueNotSet:
                    _description = "Option " + _message + " requires a value";
                    break;
                case PortInvalid:
                    _description = "Invalid port " + _message;
                    break;
                case JidInvalid:
                    _description = "Invalid JID " + _message;
                    break;
                case ValueInvalid:
                    _description = "Invalid value for " + _message;
                    break;
                case OptionsConflicting:
                    _description =
                    "Option " + _message + " set more than one time";
                    break;
                default:
                    setInvalid();
            }
        }/*}}}*/
    }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
