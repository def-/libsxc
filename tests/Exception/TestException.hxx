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

#ifndef TESTS_EXCEPTION_TESTEXCEPTION_HXX
#define TESTS_EXCEPTION_TESTEXCEPTION_HXX

// INCLUDE/*{{{*/

#include <cppunit/extensions/HelperMacros.h>

/*}}}*/

namespace libsxc
{
  class TestException : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE(TestException);
      CPPUNIT_TEST(testGetMessage);
      CPPUNIT_TEST(testBacktrace);
    CPPUNIT_TEST_SUITE_END();

    public:
      void setUp();
      void tearDown();

      void testGetMessage();
      void testBacktrace();

  };
}

#endif // TESTS_EXCEPTION_TESTEXCEPTION_HXX
// Use no tabs at all; two spaces indentation; max. eighty chars per line.
// vim: et ts=2 sw=2 sts=2 tw=80 fdm=marker
