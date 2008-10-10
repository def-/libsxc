// LICENSE/*{{{*/
/*
  sxc - Simple Xmpp Client
  Copyright (C) 2008 Dennis Felsing, Andreas Waidler

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*}}}*/



#ifndef OPTION_OPTION_HXX
#define OPTION_OPTION_HXX


// INCLUDE/*{{{*/

#include <libsxc/Option/OptionBase.hxx>
#include <libsxc/Option/Parser.hxx>
#include <libsxc/Exception/OptionException.hxx>

/*}}}*/

namespace libsxc
{
    /**
     * @brief Contains a flexible option parsing system.
     */
    namespace Option
    {
        /**
         * @author Dennis Felsing
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

#endif // OPTION_OPTION_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
