#line 1 "libsxc:Option/OptionBase.cxx"
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

#include <string>
#include <stdexcept>

#include <libsxc/Option/OptionBase.hxx>

/*}}}*/

namespace libsxc
{
  namespace Option
  {
    OptionBase::OptionBase(/*{{{*/
      char shortName,
      std::string longName,
      std::string variable,
      std::string description,
      bool requiresArgument,
      bool isObligatory)
    : _isSet(false),
      _shortName(shortName),
      _longName(longName),
      _variable(variable),
      _description(description),
      _requiresArgument(requiresArgument),
      _isObligatory(isObligatory)
    {
    }/*}}}*/

    void OptionBase::setValue(std::string rawValue)/*{{{*/
    {
      throw std::logic_error(
        "OptionBase::setValue() was called instead of the Option's "
        "implementation of the method.");
    }/*}}}*/

    char OptionBase::getShortName()/*{{{*/
    {
      return _shortName;
    }/*}}}*/
    std::string OptionBase::getLongName()/*{{{*/
    {
      return _longName;
    }/*}}}*/
    std::string OptionBase::getName()/*{{{*/
    {
      if ("" != _longName)
        return "--" + _longName;
      else if (' ' != _shortName)
        return "-" + _shortName;
      return _variable;
    }/*}}}*/
    std::string OptionBase::getVariable()/*{{{*/
    {
      return _variable;
    }/*}}}*/
    std::string OptionBase::getDescription()/*{{{*/
    {
      return _description;
    }/*}}}*/
    bool OptionBase::getRequiresArgument()/*{{{*/
    {
      return _requiresArgument;
    }/*}}}*/
    bool OptionBase::getIsObligatory()/*{{{*/
    {
      return _isObligatory;
    }/*}}}*/
    bool OptionBase::getIsSet()/*{{{*/
    {
      return _isSet;
    }/*}}}*/
  }
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
