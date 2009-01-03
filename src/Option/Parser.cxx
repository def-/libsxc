#line 2 "libsxc:Option/Parser.cxx"
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

#include <sstream>
#include <string>
#include <vector>

#include <libsxc/Option/Parser.hxx>
#include <libsxc/Exception/OptionException.hxx>

#ifdef HAVE_CONFIG_H
# include <config.hxx>
#endif

#include <libsxc/Logger.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    bool Parser::doShowHelp()/*{{{*/
    {
      return _showHelp;
    }/*}}}*/
    bool Parser::doShowVersion()/*{{{*/
    {
      return _showVersion;
    }/*}}}*/

    void Parser::addOption(OptionBase *option)/*{{{*/
    {
      std::ostringstream ss;
      ss << "Add Option: "
         << "(short: \"" << option->getShortName()
         << "\", long: \"" << option->getLongName()
         << "\", var: \"" << option->getVariable()
         << "\", desc: \"" << option->getDescription()
         << "\", req: \"" << option->getRequiresArgument()
         << "\", oblig: \"" << option->getIsObligatory() << "\")";
      LOG<Debug>(ss.str());

      // The options having a name have to be parsed first. After
      // that all the nameless options can be passed. Therefore the
      // nameless are appended to an own vector.
      if (option->getLongName() == ""
      && option->getShortName() == ' ') {
        _namelessOptions.push_back(option);
      } else {
        // Check for conflict before adding.
        for(
        std::vector<OptionBase *>::iterator availOption =
        _options.begin();
        availOption != _options.end();
        ++availOption) {
          // Allow multiple options without a short name.
          if (option->getShortName() != ' '
          && (*availOption)->getShortName()
          == option->getShortName())
            throw Exception::OptionException(
              Exception::OptionsConflicting,
              "-" + option->getShortName());
          if ((*availOption)->getLongName() == option->getLongName())
            throw Exception::OptionException(
              Exception::OptionsConflicting,
              "--" + option->getLongName());
        }

        _options.push_back(option);
      }
    }/*}}}*/
    void Parser::parse(char *argv[])/*{{{*/
    {
      _programName = argv[0];

      std::vector<std::string> arguments;

      for (int i = 1; argv[i]; ++i)
        arguments.push_back(argv[i]);

      // Parse normal options./*{{{*/

      // Walk through every option and check it for every argument
      // supplied. If something was found, remove it from the
      // arguments vector.
      for (
      std::vector<OptionBase *>::iterator option = _options.begin();
      option != _options.end();
      ++option) {
        for (
        std::vector<std::string>::iterator argument = arguments.begin();
        argument != arguments.end();) {
          LOG<Debug>(
            "Parse normal option: (option: \"" +
            (*option)->getName() + "\", arg: \"" +
            *argument + "\").");

          if ("--help" == *argument || "-h" == *argument) {
            _showHelp = true;
            return;
          } else if ("--version" == *argument || "-V" == *argument) {
            _showVersion = true;
            return;
          } else if ("--" + (*option)->getLongName() == *argument
          || std::string("-")
          + (*option)->getShortName() == *argument) {
            if ((*option)->getRequiresArgument()) {
              if (argument + 1 == arguments.end())
                throw Exception::OptionException(
                  Exception::ValueNotSet,
                  (*option)->getName());
              // Get the next argument.
              argument = arguments.erase(argument);
              (*option)->setValue(*argument);
            } else {
              (*option)->setValue();
            }
            argument = arguments.erase(argument);
          } else {
            // An argument with multiple options set. (-ab for
            // example to set -a and -b)
            while (argument->length() > 1
            && argument->at(0) == '-'
            && argument->at(1) != '-'
            && argument->find((*option)->getShortName())
               != std::string::npos) {
              (*option)->setValue();
              // Delete the character.
              argument->erase(argument->begin()
              + argument->find(((*option)->getShortName())));
            }
            ++argument;
          }
        }

        if ((*option)->getIsObligatory() && !(*option)->getIsSet()) {
          throw Exception::OptionException(
            Exception::OptionNotSet,
            (*option)->getName());
        }
      }/*}}}*/

      // Parse nameless options./*{{{*/
      for (
      std::vector<OptionBase *>::iterator option =
      _namelessOptions.begin();
      option != _namelessOptions.end();
      ++option) {
        for (
        std::vector<std::string>::iterator argument = arguments.begin();
        argument != arguments.end() && !(*option)->getIsSet();) {
          LOG<Debug>(
            "Parse nameless option: (option: \"" +
            (*option)->getName() + "\", arg: \"" +
            *argument + "\").");

          if (argument->at(0) != '-') {
            (*option)->setValue(*argument);
            argument = arguments.erase(argument);
          } else {
            ++argument; // Throwing later when checking the size.
          }
        }

        if ((*option)->getIsObligatory() && !(*option)->getIsSet())
          throw Exception::OptionException(
            Exception::OptionNotSet,
            (*option)->getName());
      }/*}}}*/

      if (arguments.size())
        throw Exception::OptionException(
          Exception::OptionUnknown,
          arguments.at(0));
    }/*}}}*/
    std::vector<std::string> Parser::getUsage()/*{{{*/
    {
      std::vector<std::string> out;

      out.push_back("Usage: " + _programName);

      // Handle normal options./*{{{*/
      for (
      std::vector<OptionBase *>::iterator option = _options.begin();
      option != _options.end();
      ++option) {
        out.front() += getUsageShort(**option);
        out.push_back(getUsageLine(**option));
      }/*}}}*/

      // Handle nameless options./*{{{*/
      for (
      std::vector<OptionBase *>::iterator option =
      _namelessOptions.begin();
      option != _namelessOptions.end();
      ++option) {
        out.front() += getUsageShort(**option);
        out.push_back(getUsageLine(**option));
      }/*}}}*/

      return out;
    }/*}}}*/

    std::string Parser::getUsageShort(OptionBase option)/*{{{*/
    {
      std::string text;

      if (option.getShortName() != ' ') {
        text = std::string("-") + option.getShortName();
      } else if (option.getLongName() != "") {
        text = std::string("--") + option.getLongName();
      }
      if (option.getRequiresArgument())
        text += " " + option.getVariable();
      if (!option.getIsObligatory()) {
        text = " [" + text + "]";
      } else if (option.getShortName() != ' '
      || option.getLongName() != "") {
        text = " " + text;
      }

      return text;
    }/*}}}*/
    std::string Parser::getUsageLine(OptionBase option)/*{{{*/
    {
      std::string line;

      if (option.getShortName() != ' ') {
        line += std::string("-") + option.getShortName();
        if (option.getLongName() != "")
          line += "/";
      }
      if (option.getLongName() != "")
        line += std::string("--") + option.getLongName();
      if (option.getLongName() != "" || option.getShortName() != ' ')
        if (option.getRequiresArgument())
          line += std::string(" ");
      if (option.getRequiresArgument())
        line += option.getVariable();
      line += ": " + option.getDescription();

      return line;
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
