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



#ifndef OPTION_OPTIONBASE_HXX
#define OPTION_OPTIONBASE_HXX


// INCLUDE/*{{{*/

#include <string>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    /**
     * @brief The base class for options.
     */
    class OptionBase
    {
      public:
        //OptionBase(/*{{{*/

        /**
         * @brief Create a new option base.
         *
         * Construct a new option base object.
         *
         * @param shortName A short option name. ('x' for "-x")
         * @param longName A long option name. ("foo" for --foo)
         * @param variable How to call the variable in the usage
         *        output.
         * @param description A description of the option.
         * @param requiresArgument Whether this option needs an
         *        argument. Normally only booleans don't need one.
         * @param isObligatory Whether the option has to be set.
         */
        OptionBase(
          char shortName,
          std::string longName,
          std::string variable,
          std::string description,
          bool requiresArgument,
          bool isObligatory);

  /*}}}*/

        //virtual void setValue(std::string rawValue="");/*{{{*/

        /**
         * @brief Set the value. Implement this in the derived class.
         *
         * @param rawValue The raw value as a string.
         */
        virtual void setValue(std::string rawValue="");

  /*}}}*/

        //char getShortName();/*{{{*/

        /**
         * @brief Get the short name.
         *
         * @return The short name.
         */
        char getShortName();

  /*}}}*/
        //std::string getLongName();/*{{{*/

        /**
         * @brief Get the long name.
         *
         * @return The long name.
         */
        std::string getLongName();

  /*}}}*/
        //std::string getName();/*{{{*/

        /**
         * @brief Get the long name, or if not specified the short
         *        name.
         *
         * @return The name.
         */
        std::string getName();

  /*}}}*/
        //std::string getVariable();/*{{{*/

        /**
         * @brief Get the variable name.
         *
         * @return The variable name.
         */
        std::string getVariable();

  /*}}}*/
        //std::string getDescription();/*{{{*/

        /**
         * @brief Get the description.
         *
         * @return The description.
         */
        std::string getDescription();

  /*}}}*/
        //bool getRequiresArgument();/*{{{*/

        /**
         * @brief Get whether an argument is required.
         *
         * @return Whether an argument is required.
         */
        bool getRequiresArgument();

  /*}}}*/
        //bool getIsObligatory();/*{{{*/

        /**
         * @brief Get whether the option is obligatory.
         *
         * @return Whether the option is obligatory.
         */
        bool getIsObligatory();

  /*}}}*/
        //bool getIsSet();/*{{{*/

        /**
         * @brief Get whether the option has already been set.
         *
         * @return Whether the option has already been set.
         */
        bool getIsSet();

  /*}}}*/

      protected:
        //bool _isSet;/*{{{*/

        /// Whether the option has already been set.
        bool _isSet;

  /*}}}*/

      private:
        //char _shortName;/*{{{*/

        /// The short name.
        char _shortName;

  /*}}}*/
        //std::string _longName;/*{{{*/

        /// The long name.
        std::string _longName;

  /*}}}*/
        //std::string _variable;/*{{{*/

        /// The variable name.
        std::string _variable;

  /*}}}*/
        //std::string _description;/*{{{*/

        /// The description.
        std::string _description;

  /*}}}*/
        //bool _requiresArgument;/*{{{*/

        /// Whether an argument is required.
        bool _requiresArgument;

  /*}}}*/
        //bool _isObligatory;/*{{{*/

        /// Whether the option is obligatory.
        bool _isObligatory;

  /*}}}*/
    };
  }
}


#endif // OPTION_OPTIONBASE_HXX

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
