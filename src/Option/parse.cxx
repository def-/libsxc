#line 1 "libsxc:Option/parse.cxx"
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

#include <iostream>
#include <string>

#include <libsxc/Option/Parser.hxx>
#include <libsxc/Logger.hxx>
#include <libsxc/Option/parse.hxx>
#include <libsxc/Exception/OptionException.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    void parse(Parser &parser, char **argv)
    {
      try {
        parser.parse(argv);
      } catch (libsxc::Exception::OptionException &e) {
        if (libsxc::Exception::ShowUsage == e.getType()) {
          std::cerr << parser.getHelp();
        } else if (libsxc::Exception::ShowVersion == e.getType()) {
          std::cerr << parser.getVersion() << std::endl;
          return;
        } else {
          // FIXME: Throw something.
          //LOG<Error>(e.getDescription());
        }

        std::vector<std::string> usage = parser.getUsage();
        for(
          std::vector<std::string>::iterator it = usage.begin();
          usage.end() != it;
          ++it) {
          std::cerr << *it << std::endl;
        }

        if (e.getType() < 0) // No error. (ShowUsage, ShowVersion)
          return;
        //return e.getType();
        // FIXME: Retrhow something.
      } catch (libsxc::Exception::Exception &e) {
        LOG<Error>(e.getDescription());
        //return e.getType();
        // FIXME: Rethrow something.
      }
    }
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
