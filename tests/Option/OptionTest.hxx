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


// INCLUDE/*{{{*/

#include <string>
#include <gloox/jid.h>
#include <cppunit/extensions/HelperMacros.h>

#include <libsxc/Exception/OptionException.hxx>
#include <libsxc/Option/Parser.hxx>
#include <libsxc/Option/Option.hxx>
#include <libsxc/Option/OptionPort.hxx>

/*}}}*/


#ifndef TESTS_OPTION_OPTIONTEST_HXX
#define TESTS_OPTION_OPTIONTEST_HXX


namespace libsxc
{
  class OptionTest : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE(OptionTest);
      CPPUNIT_TEST(testCorrectParsing);
      CPPUNIT_TEST(testStringParsing);
      CPPUNIT_TEST(testMissingObligatoryOption);
      CPPUNIT_TEST(testValueNotSet);
      CPPUNIT_TEST(testOptionSetMultipleTimes);
      CPPUNIT_TEST(testUnknownLongOption);
      CPPUNIT_TEST(testUnknownShortOption);
      CPPUNIT_TEST(testConflictingShortName);
      CPPUNIT_TEST(testConflictingLongName);
      CPPUNIT_TEST(testJids);
      CPPUNIT_TEST(testConvertType);
    CPPUNIT_TEST_SUITE_END();

    public:
      void setUp();
      void tearDown();

      void testCorrectParsing();
      void testStringParsing();
      void testMissingObligatoryOption();
      void testValueNotSet();
      void testOptionSetMultipleTimes();
      void testUnknownLongOption();
      void testUnknownShortOption();
      void testConflictingShortName();
      void testConflictingLongName();
      void testJids();
      void testConvertType();

    private:
      void doTestInvalidJid(std::string rawJid);
      void doTestValidJid(std::string rawJid);
      template<typename T> void doTestInvalidConvert(
        std::string rawValue);
      template<typename T> void doTestValidConvert(std::string rawValue);

      Option::Parser *_parser;
      Option::Option<bool> *_bool;
      Option::Option<bool> *_bool2;
      Option::Option<int> *_int;
      Option::Option<float> *_float;
      Option::Option<char> *_char;
      Option::Option<long> *_long;
      Option::Option<std::string> *_string;
      Option::Option<int> *_default;
      Option::Option<std::string> *_default2;
  };
}


#endif // TESTS_OPTION_OPTIONTEST_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
