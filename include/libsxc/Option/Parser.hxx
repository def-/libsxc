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



#ifndef OPTION_PARSER_HXX
#define OPTION_PARSER_HXX


// INCLUDE/*{{{*/

#include <string>
#include <vector>

#include <libsxc/Option/OptionBase.hxx>

/*}}}*/

namespace libsxc
{
    namespace Option
    {
        /**
         * @brief An option parser
         *
         * This class parses program options.
         */
        class Parser
        {
            public:
                //void addOption(OptionBase *option);/*{{{*/

                /**
                 * @brief Add an option to be parsed.
                 *
                 * @param option The option.
                 */
                void addOption(OptionBase *option);

    /*}}}*/
                //void parse(const char *argv[]);/*{{{*/

                /**
                 * @brief Parse all options.
                 *
                 * Parse all options that have been added before using @ref
                 * addOption(). Errors get thrown.
                 *
                 * @param argv The raw arguments.
                 */
                void parse(char *argv[]);

    /*}}}*/
                //std::vector<std::string> getUsage();/*{{{*/

                /**
                 * @brief Show the usage.
                 *
                 * Output to stderr how to use the program.
                 */
                std::vector<std::string> getUsage();

    /*}}}*/

            private:
                //std::string getUsageShort(OptionBase option);/*{{{*/

                /**
                 * @brief Get the short usage information about an option.
                 *
                 * This function formats a string to print it in the first line
                 * of the program usage.
                 *
                 * @param option The option to format.
                 *
                 * @return The string to be printed.
                 */
                std::string getUsageShort(OptionBase option);

    /*}}}*/
                //std::string getUsageLine(OptionBase option);/*{{{*/

                /**
                 * @brief Get the long usage information about an option.
                 *
                 * This function returns a whole line to inform the user about
                 * a program option more verbosely than @ref getUsageShort().
                 *
                 * @param option The option to format.
                 *
                 * @return The string to be printed.
                 */
                std::string getUsageLine(OptionBase option);

    /*}}}*/

                //std::vector<OptionBase *> _options;/*{{{*/

                /// The normal options.
                std::vector<OptionBase *> _options;

    /*}}}*/
                //std::vector<OptionBase *> _namelessOptions;/*{{{*/

                /// The options that are not introduced by a "-x" or "--foo".
                std::vector<OptionBase *> _namelessOptions;

    /*}}}*/
                //std::string _programName;/*{{{*/

                /// The name of the program.
                std::string _programName;

    /*}}}*/
        };
    }
}


#endif // OPTION_PARSER_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
