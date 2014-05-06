##process this file with automake to produce Makefile.in

INCLUDES=-I. @DEPS_CFLAGS@

lib_LTLIBRARIES = libdiffmark.la

diffmarkincdir = $(pkgincludedir)
diffmarkinc_HEADERS = compare.hh compareimpl.hh diff.hh lcs.hh lcsimpl.hh link.hh merge.hh namespacecollector.hh nspace.hh target.hh xbuffer.hh xdoc.hh xutil.hh

libdiffmark_la_SOURCES = compare.cc diff.cc link.cc merge.cc namespacecollector.cc nspace.cc target.cc xbuffer.cc xdoc.cc xutil.cc

libdiffmark_la_LDFLAGS = -rpath $(libdir) -version-info 2:3:1 @DEPS_LIBS@ -lstdc++

