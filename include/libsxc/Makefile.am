SUBDIRS = Exception Option

installdir = $(includedir)/$(PACKAGE)
install_HEADERS = generateString.hxx getHostName.hxx

# Only remove our own directory. No weird stuff like removing every empty
# dir.
uninstall-hook:
	rm -rf $(includedir)/$(PACKAGE)
