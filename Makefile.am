# Use local m4-macros when building configure with autoreconf
ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src tests include

pkgconfigdir = $(libdir)/pkgconfig
# Include the version number to support parallel installs of different
# versions.
pkgconfig_DATA = $(PACKAGE).pc

doxygen:
	doxygen
