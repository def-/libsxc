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

#include <TestException.hxx>

#include <libsxc/Exception/Exception.hxx>
#include <libsxc/Exception/RuntimeError.hxx>
#include <libsxc/Exception/LogicError.hxx>
#include <libsxc/Exception/Overflow.hxx>
#include <libsxc/Exception/Underflow.hxx>
#include <libsxc/Exit/Code.hxx>

#include <cppunit/extensions/HelperMacros.h>

#include <string>

/*}}}*/

namespace libsxc
{
  void TestException::setUp()/*{{{*/
  {
  }

/*}}}*/
  void TestException::tearDown()/*{{{*/
  {
  }

/*}}}*/

  void TestException::testGetMessage()/*{{{*/
  {
    Exception::Exception e1("basic exception", Exit::General);
    Exception::RuntimeError e2("error detected at runtime");
    Exception::LogicError e3("error in program logic");
    Exception::Overflow e4("something overflowed");
    Exception::Underflow e5("something underflowed");
    CPPUNIT_ASSERT_EQUAL(
      std::string("basic exception"), std::string(e1.getMessage()));
    CPPUNIT_ASSERT_EQUAL(
      std::string("error detected at runtime"), std::string(e2.getMessage()));
    CPPUNIT_ASSERT_EQUAL(
      std::string("error in program logic"), std::string(e3.getMessage()));
    CPPUNIT_ASSERT_EQUAL(
      std::string("something overflowed"), std::string(e4.getMessage()));
    CPPUNIT_ASSERT_EQUAL(
      std::string("something underflowed"), std::string(e5.getMessage()));
  }

/*}}}*/
  void TestException::testBacktrace()/*{{{*/
  {
    Exception::LogicError cause("you fail");
    Exception::LogicError rethrow("you fail at failing", cause);
    Exception::LogicError result("you fail at false failing", rethrow);
    std::string expected("you fail\nyou fail at failing\n");
    expected.append("you fail at false failing");
    CPPUNIT_ASSERT_EQUAL(expected, std::string(result.what()));
  }

/*}}}*/
}

// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
