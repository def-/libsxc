SUBDIRS = Option
check_PROGRAMS = tests

TESTS = tests
tests_CPPFLAGS = -I$(top_srcdir)/include $(CPPUNIT_CFLAGS)
tests_CXXFLAGS = $(CPPUNIT_LIBS)
tests_LDADD = $(top_srcdir)/src/libsxc.la $(top_srcdir)/tests/Option/libOption.la
tests_SOURCES = main.cxx testRegistry.cxx
