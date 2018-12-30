# Process this file with autoconf to produce a configure script.
AC_INIT(diffmark, 0.10, vbarta@mangrove.cz)
AC_CONFIG_SRCDIR(cmd/dm.cc)
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(diffmark, 0.10)

# Checks for programs.
AC_PROG_CXX
AM_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC

# Checks for libraries.
PKG_CHECK_MODULES([DEPS], libxml-2.0)
AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)

AC_CONFIG_FILES([Makefile lib/Makefile cmd/Makefile doc/Makefile diffmark.test/Makefile testdata/Makefile testdata/diff/Makefile testdata/merge/Makefile testdata/roundup/Makefile testdata/faildiff/Makefile testdata/failmerge/Makefile])
AC_OUTPUT

