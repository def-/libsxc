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
#include <exception>
#include <gloox/jid.h>
#include <cppunit/extensions/HelperMacros.h>

#include <OptionTest.hxx>
#include <libsxc/Option/Parser.hxx>
#include <libsxc/Option/Option.hxx>
#include <libsxc/Option/OptionPort.hxx>

#include <libsxc/Option/Exception/MissingValue.hxx>
#include <libsxc/Option/Exception/MissingOption.hxx>
#include <libsxc/Option/Exception/UnknownOption.hxx>

/*}}}*/

namespace libsxc
{
  void OptionTest::setUp()/*{{{*/
  {
    _parser = new Option::Parser;

    _bool = new Option::Option<bool>(
      _parser, 'a', "bool", "description");

    _bool2 = new Option::Option<bool>(
      _parser, 'g', "bool2", "description");

    _int = new Option::Option<int>(
      _parser, 'b', "int", "def", "description", 42);

    _float = new Option::Option<float>(
      _parser, 'c', "float", "ghi", "description");

    _char = new Option::Option<char>(
      _parser, 'd', "char", "jkl", "description", 'x');

    _long = new Option::Option<long>(
      _parser, 'e', "long", "foobar", "description");

    _string = new Option::Option<std::string>(
      _parser, 'f', "string", "var", "description", "default");

    _default = new Option::Option<int>(
      _parser, ' ', "", "foo", "description");

    _default2 = new Option::Option<std::string>(
      _parser, ' ', "", "foob", "description");
  }/*}}}*/
  void OptionTest::tearDown()/*{{{*/
  {
    delete _parser;

    delete _bool;
    delete _bool2;
    delete _int;
    delete _float;
    delete _char;
    delete _long;
    delete _string;
    delete _default;
    delete _default2;
  }/*}}}*/

  void OptionTest::testCorrectParsing()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--float", "1.2345", "--char", "c", "-e",
      "123456789", "123", "bar", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (std::exception &e) {
      CPPUNIT_FAIL(e.what());
    }

    CPPUNIT_ASSERT(_bool->getValue());
    CPPUNIT_ASSERT(!_bool2->getValue());
    CPPUNIT_ASSERT_EQUAL(42, _int->getValue());
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.2345, _float->getValue(), 0.00001);
    CPPUNIT_ASSERT_EQUAL('c', _char->getValue());
    CPPUNIT_ASSERT_EQUAL(123456789L, _long->getValue());
    CPPUNIT_ASSERT_EQUAL(std::string("default"), _string->getValue());
    CPPUNIT_ASSERT_EQUAL(123, _default->getValue());
    CPPUNIT_ASSERT_EQUAL(std::string("bar"), _default2->getValue());
  }/*}}}*/
  void OptionTest::testStringParsing()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "123", "bar", "--long", "1", "--float", "0", "--string", "abc def ghi jklsak", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (std::exception &e) {
      CPPUNIT_FAIL(e.what());
    }

    CPPUNIT_ASSERT_EQUAL(std::string("abc def ghi jklsak"), _string->getValue());
  }/*}}}*/
  void OptionTest::testMissingObligatoryOption()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--char", "c", "-e", "123456789", "123",
      "bar", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (libsxc::Option::Exception::MissingOption &e) {
        return;
    }
    CPPUNIT_FAIL("Missing obligatory option ignored");
  }/*}}}*/
  void OptionTest::testValueNotSet()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--char", "c", "-e", "123456789", "123",
      "bar", "--float", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (libsxc::Option::Exception::MissingValue &e) {
      return;
    }
    CPPUNIT_FAIL("Missing value ignored");
  }/*}}}*/
  void OptionTest::testOptionSetMultipleTimes()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--float", "1.2345", "--char", "d", "--char",
      "c", "-e", "123456789", "123", "bar", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (libsxc::Option::Exception::Conflict &e) {
      return;
    }
    CPPUNIT_FAIL("Conflicting option ignored");
  }/*}}}*/
  void OptionTest::testUnknownLongOption()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--float", "1.2345", "--zomfg", "--char", "c",
      "-e", "123456789", "123", "bar", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (libsxc::Option::Exception::UnknownOption &e) {
      return;
    }
    CPPUNIT_FAIL("Ignored adding of unknown option.");
  }/*}}}*/
  void OptionTest::testUnknownShortOption()/*{{{*/
  {
    const char *argv[] = {
      "sxc-test", "-a", "--float", "1.2345", "-z", "--char", "c",
      "-e", "123456789", "123", "bar", NULL};

    try {
      _parser->parse(const_cast<char **>(argv));
    } catch (libsxc::Option::Exception::UnknownOption &e) {
      return;
    }
    CPPUNIT_FAIL("Ignored adding of unknown option.");
  }/*}}}*/
  void OptionTest::testConflictingShortName()/*{{{*/
  {
    try {
      Option::Option<int> conflicting(
        _parser, 'd', "conflicting", "barfoo", "descr");
    } catch (libsxc::Option::Exception::Conflict &e) {
      return;
    }
    CPPUNIT_FAIL("Conflicting option ignored");
  }/*}}}*/
  void OptionTest::testConflictingLongName()/*{{{*/
  {
    try {
      Option::Option<char> conflicting(
        _parser, 'z', "long", "bar", "descr", 'y');
    } catch (libsxc::Option::Exception::Conflict &e) {
      return;
    }
    CPPUNIT_FAIL("Conflicting option ignored");
  }/*}}}*/
  void OptionTest::testJids()/*{{{*/
  {
    doTestInvalidJid("foo");
    doTestInvalidJid("123");
    doTestInvalidJid("abc@");
    doTestInvalidJid("@@@");
    doTestInvalidJid("@bcd");

    doTestValidJid("foo@bar");
    doTestValidJid("ra23@192.168.0.1");
    doTestValidJid("wu@127.0.0.1/home");
  }/*}}}*/
  void OptionTest::testConvertType()/*{{{*/
  {
    doTestInvalidConvert<int>("foo");
    doTestInvalidConvert<long>("abc");
    doTestInvalidConvert<char>("ab");
    doTestInvalidConvert<float>("foo");
    doTestInvalidConvert<double>("foo");

    doTestValidConvert<std::string>("foo@bar");
    doTestValidConvert<int>("42");
    doTestValidConvert<long>("42");
    doTestValidConvert<char>("a");
    doTestValidConvert<float>("42.123456");
    doTestValidConvert<double>("42.123456");
  }/*}}}*/
  void OptionTest::doTestInvalidJid(std::string rawJid)/*{{{*/
  {
    Option::Parser parser;
    Option::Option<gloox::JID> jid(
      &parser, 'j', "jid", "barfoo", "descr");

    try {
      jid.setValue(rawJid);
    } catch (libsxc::Option::Exception::InvalidValue &e) {
      return;
    }
    CPPUNIT_FAIL("Invalid JID " + rawJid + " accepted");
  }/*}}}*/
  void OptionTest::doTestValidJid(std::string rawJid)/*{{{*/
  {
    Option::Parser parser;
    Option::Option<gloox::JID> jid(
      &parser, 'j', "jid", "barfoo", "descr");

    try {
      jid.setValue(rawJid);
    } catch (libsxc::Option::Exception::InvalidValue &e) {
      CPPUNIT_FAIL("Valid JID " + rawJid + " not accepted");
    }
  }/*}}}*/
  template<typename T> void OptionTest::doTestInvalidConvert(/*{{{*/
    std::string rawValue)
  {
    Option::Parser parser;
    Option::Option<T> option(
      &parser, 'a', "abc", "foobar", "descr");

    try {
      option.setValue(rawValue);
    } catch (libsxc::Option::Exception::InvalidValue &e) {
      return;
    }
    CPPUNIT_FAIL("Invalid type conversion of " + rawValue + " worked");
  }/*}}}*/
  template<typename T> void OptionTest::doTestValidConvert(/*{{{*/
    std::string rawValue)
  {
    Option::Parser parser;
    Option::Option<T> option(
      &parser, 'a', "abc", "foobar", "descr");

    try {
      option.setValue(rawValue);
    } catch (libsxc::Option::Exception::InvalidValue &e) {
      CPPUNIT_FAIL(
        "Valid type conversion of " + rawValue + " did not work");
    }
  }/*}}}*/
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
