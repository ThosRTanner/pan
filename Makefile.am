SUBDIRS = . uulib pan po

DIST_SUBDIRS = . uulib pan po help

if ENABLE_MANUAL
SUBDIRS += help
endif

org.gnome.pan.desktop: org.gnome.pan.desktop.in
	$(AM_V_GEN)$(MSGFMT) --desktop --template $< -d $(top_srcdir)/po -o $@
desktopdir = $(datadir)/applications
desktop_DATA = org.gnome.pan.desktop

org.gnome.pan.metainfo.xml: org.gnome.pan.metainfo.xml.in
	$(AM_V_GEN)$(MSGFMT) --xml --template $< -d $(top_srcdir)/po -o $@
appdatadir = $(datadir)/metainfo
appdata_DATA = org.gnome.pan.metainfo.xml

man_MANS = pan.1

CLEANFILES = \
 $(appdata_DATA) \
 $(desktop_DATA)

DISTCLEANFILES = \
 README.windows \
 pan-git.version

MAINTAINERCLEANFILES = \
 $(srcdir)/aclocal.m4 \
 $(srcdir)/config.guess \
 $(srcdir)/config.h.in \
 $(srcdir)/config.sub \
 $(srcdir)/configure \
 $(srcdir)/depcomp \
 $(srcdir)/install-sh \
 $(srcdir)/missing \
 $(srcdir)/mkinstalldirs \
 `find "$(srcdir)" -type f -name Makefile.in -print` \
 $(NULL)

EXTRA_DIST = \
 COPYING-DOCS \
 README.org \
 README.windows \
 org.gnome.pan.desktop.in \
 org.gnome.pan.metainfo.xml.in \
 pan-git.version \
 $(man_MANS) \
 $(NULL)

