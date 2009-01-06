SUBDIRS = Debug Error Exception Option Signal

lib_LTLIBRARIES = libsxc.la
libsxc_la_CPPFLAGS = -I$(top_srcdir)/include $(GLOOX_CFLAGS)
libsxc_la_CXXFLAGS = $(GLOOX_LIBS)
libsxc_la_LIBADD = \
  Debug/libDebug.la \
  Error/libError.la \
  Exception/libException.la \
  Option/libOption.la \
  Signal/libSignal.la
libsxc_la_SOURCES = generateString.cxx getHostName.cxx
