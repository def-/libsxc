SUBDIRS = Exception Option

lib_LTLIBRARIES = libsxc.la
libsxc_la_CPPFLAGS = -I$(top_srcdir)/include $(GLOOX_CFLAGS)
libsxc_la_CXXFLAGS = $(GLOOX_LIBS)
libsxc_la_LIBADD = Exception/libException.la Option/libOption.la
libsxc_la_SOURCES = generateString.cxx getHostName.cxx Logger.cxx
