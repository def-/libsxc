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



#ifndef LIBSXC_OPTION_OPTION_HXX
#define LIBSXC_OPTION_OPTION_HXX


// INCLUDE/*{{{*/

#include <libsxc/Option/OptionBase.hxx>
#include <libsxc/Option/Parser.hxx>

/*}}}*/

namespace libsxc
{
  /**
   * @brief Contains a flexible option parsing system.
   */
  namespace Option
  {
    /**
     * @brief A representation of a program option.
     */
    template <typename T>
    class Option : public OptionBase
    {
      public:
        //Option(parser, short, long, var, desc, default, oblig);/*{{{*/

        /**
         * @brief Create a new option.
         *
         * Construct a new option object and add it to the parser.
         *
         * @warning This constructor takes no default value and no
         *          "default"-flag. This only makes sense when using
         *          boolean as type.
         *
         * @param parser The parser the object will be added to.
         * @param shortName A short option name. ('x' for "-x")
         * @param longName A long option name. ("foo" for --foo)
         * @param description A description of the option.
         */
        Option(
          Parser *parser,
          char shortName,
          std::string longName,
          std::string description);

  /*}}}*/
        //Option(parser, short, long, var, description, default);/*{{{*/

        /**
         * @brief Create a new option.
         *
         * Construct a new option object and add it to the parser.
         *
         * @note This constructor takes a default value, so the option
         *       is optional. This makes no sense for booleans, as they
         *       always default to "false" and are optional.
         *
         * @param parser The parser the object will be added to.
         * @param shortName A short option name. ('x' for "-x")
         * @param longName A long option name. ("foo" for --foo)
         * @param variable How to call the variable in the usage output.
         * @param description A description of the option.
         * @param defaultValue The value to be set if not specified.
         */
        Option(
          Parser *parser,
          char shortName,
          std::string longName,
          std::string variable,
          std::string description,
          T defaultValue);

  /*}}}*/
        //Option(parser, shortName, longName, var, description);/*{{{*/

        /**
         * @brief Create a new option.
         *
         * Construct a new option object and add it to the parser.
         *
         * @note This constructor takes no default value, so it is
         *       obligatory. This makes no sense for booleans, as they
         *       always are optional, else you couldn't not set them...
         *
         * @param parser The parser the object will be added to.
         * @param shortName A short option name. ('x' for "-x")
         * @param longName A long option name. ("foo" for --foo)
         * @param variable How to call the variable in the usage output.
         * @param description A description of the option.
         */
        Option(
          Parser *parser,
          char shortName,
          std::string longName,
          std::string variable,
          std::string description);

  /*}}}*/

        //void setValue(std::string rawValue="");/*{{{*/

        /**
         * @brief Set the value.
         *
         * @param rawValue The raw value as a string.
         */
        void setValue(std::string rawValue="");

  /*}}}*/
        //T getValue();/*{{{*/

        /**
         * @brief Get the value.
         *
         * @return The value.
         */
        T getValue();

  /*}}}*/

      private:
        //void doSetValue(std::string rawValue="");/*{{{*/

        /**
         * @brief The function doing the real work.
         *
         * @param rawValue The raw value as a string.
         */
        void doSetValue(std::string rawValue="");

  /*}}}*/

        //T _value;/*{{{*/

        /// The value.
        T _value;

  /*}}}*/
    };
  }
}

#include <libsxc/Option/Option.ixx>

#endif // LIBSXC_OPTION_OPTION_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
