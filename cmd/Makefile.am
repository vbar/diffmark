##process this file with automake to produce Makefile.in

INCLUDES=-I../lib @DEPS_CFLAGS@

bin_PROGRAMS = dm dm-merge

noinst_PROGRAMS = test-lcs test-compare

dm_SOURCES = dm.cc

dm_LDADD = ../lib/libdiffmark.la @DEPS_LIBS@ -lstdc++

dm_merge_SOURCES = dm-merge.cc

dm_merge_LDADD = ../lib/libdiffmark.la @DEPS_LIBS@ -lstdc++

test_lcs_SOURCES = test-lcs.cc testlcs.cc testlcs.hh

test_lcs_LDADD = ../lib/libdiffmark.la -lstdc++

test_compare_SOURCES = test-compare.cc

test_compare_LDADD = ../lib/libdiffmark.la @DEPS_LIBS@ -lstdc++
