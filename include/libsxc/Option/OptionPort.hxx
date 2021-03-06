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



#ifndef LIBSXC_OPTION_OPTIONPORT_HXX
#define LIBSXC_OPTION_OPTIONPORT_HXX


// INCLUDE/*{{{*/

#include <libsxc/Option/Option.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    /**
     * @brief A class representing an option for a port.
     *
     * This class checks whether the value is a valid port.
     */
    class OptionPort : public Option<int>
    {
      public:
        //OptionPort(parser, short, long, variable, description);/*{{{*/

        /**
         * @brief Create a new port option.
         *
         * Construct a new port option object and add it to the parser.
         *
         * @param parser The parser the object will be added to.
         * @param shortName A short option name. ('x' for "-x")
         * @param longName A long option name. ("foo" for --foo)
         * @param variable How to call the variable in the usage output.
         * @param description A description of the option.
         */
        OptionPort(
          Parser *parser,
          char shortName,
          std::string longName,
          std::string variable,
          std::string description);

  /*}}}*/
        virtual ~OptionPort() {}

        //void setValue(std::string rawValue);/*{{{*/

        /**
         * @brief Set the value.
         *
         * Set the port to the string given and check whether it is
         * valid.
         *
         * @param rawValue The raw value as a string.
         */
        void setValue(std::string rawValue);

  /*}}}*/
    };
  }
}


#endif // LIBSXC_OPTION_OPTIONPORT_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
