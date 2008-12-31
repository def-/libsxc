#line 1 "libsxc:libsxc/Option/Option.ixx"
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



#ifndef OPTION_OPTION_IXX
#define OPTION_OPTION_IXX


// INCLUDE/*{{{*/

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

#include <gloox/jid.h>

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
    template <typename T> Option<T>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string description)
    : OptionBase(
      shortName,
      longName,
      "",
      description,
      false,
      false)
    {
      throw std::logic_error(
        "Option \"" + longName + "\" uses constructor, that is only " +
        "for boolean options.");
    }/*}}}*/
    template <> inline Option<bool>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string description)
    : OptionBase( // To use getName().
      shortName,
      longName,
      "",
      description,
      false, // No boolean requires an argument.
      false),
      _value(false) // Default to false.
    {
      parser->addOption(this);
    }/*}}}*/
    template <typename T> Option<T>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string variable,
      std::string description,
      T defaultValue)
    : OptionBase(
      shortName,
      longName,
      variable,
      description,
      true, // All non-booleans require an argument.
      false), // Has an default value, so it doesn't have to be set.
      _value(defaultValue)
    {
      parser->addOption(this);
    }/*}}}*/
    template <> inline Option<bool>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string variable,
      std::string description,
      bool defaultValue)
    : OptionBase(
      shortName,
      longName,
      variable,
      description,
      true,
      false),
      _value(defaultValue)
    {
      throw std::logic_error(
        "Option \"" + longName + "\" uses constructor, that is only " +
        "for non-boolean options.");
    }/*}}}*/
    template <typename T> Option<T>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string variable,
      std::string description)
    : OptionBase(
      shortName,
      longName,
      variable,
      description,
      true, // All non-booleans require an argument.
      true) // Has no default value, so it is obligatory.
    {
      parser->addOption(this);
    }/*}}}*/
    template <> inline Option<bool>::Option(/*{{{*/
      Parser *parser,
      char shortName,
      std::string longName,
      std::string variable,
      std::string description)
    : OptionBase(
      shortName,
      longName,
      variable,
      description,
      true,
      true)
    {
      throw std::logic_error(
        "Option \"" + longName + "\" uses constructor, that is only " +
        "for non-boolean options.");
    }/*}}}*/

    template <typename T> void Option<T>::setValue(/*{{{*/
      std::string rawValue)
    {
      if (_isSet) // Only allow to be set one time.
        throw Exception::OptionException(
          Exception::OptionSetMultiple, getName());

      LOG<Debug>(
        "Set value: (option: \"" + getName() + "\", value: \"" +
        rawValue + "\").");

      doSetValue(rawValue);

      _isSet = true;
    }/*}}}*/
    template <typename T> void Option<T>::doSetValue(/*{{{*/
      std::string rawValue)
    {
      std::istringstream instream;

      instream.str(rawValue);
      instream >> _value;

      if (instream.bad() // Conversion failed
      || !instream.eof())
        throw Exception::OptionException(
          Exception::ValueInvalid, getName());
    }/*}}}*/
    template <> inline void Option<bool>::doSetValue(/*{{{*/
      std::string rawValue)
    {
      _isSet = true;
      _value = !_value; // Complement the value.
    }/*}}}*/
    template <> inline void Option<std::string>::doSetValue(/*{{{*/
      std::string rawValue)
    {
      _value = rawValue;
    }/*}}}*/
    template <> inline void Option<char>::doSetValue(/*{{{*/
      std::string rawValue)
    {
      if (rawValue.length() != 1)
        throw Exception::OptionException(
          Exception::ValueInvalid, getName());
      _value = rawValue.at(0);
    }/*}}}*/
    template <> inline void Option<gloox::JID>::doSetValue(/*{{{*/
      std::string rawValue)
    {
      if (!_value.setJID(rawValue)
      || _value.username().empty()
      || _value.server().empty())
        throw Exception::OptionException(
          Exception::JidInvalid,
          _value.full());
    }/*}}}*/
    template <typename T> T Option<T>::getValue()/*{{{*/
    {
      return _value;
    }/*}}}*/
  }
}

#endif // OPTION_OPTION_IXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
