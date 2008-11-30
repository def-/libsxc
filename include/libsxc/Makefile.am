SUBDIRS = Debug Error Exception Option Signal

installdir = $(includedir)/$(PACKAGE)
install_HEADERS = generateString.hxx getHostName.hxx Logger.hxx Logger.ixx

# Only remove our own directory. No weird stuff like removing every empty
# dir.
uninstall-hook:
	rm -rf $(includedir)/$(PACKAGE)
