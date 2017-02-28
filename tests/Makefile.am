## Process this file with automake to produce Makefile.in

TESTS = roman_dec invalid_roman
XFAIL_TESTS = invalid_roman
check_PROGRAMS = roman_dec invalid_roman
roman_dec_SOURCES = roman_dec.c $(top_builddir)/src/roman.h
roman_dec_CFLAGS = @CHECK_CFLAGS@
roman_dec_LDADD = $(top_builddir)/src/libroman.la @CHECK_LIBS@
invalid_roman_SOURCES = invalid_roman.c $(top_builddir)/src/roman.h
invalid_roman_CFLAGS = @CHECK_CFLAGS@
invalid_roman_LDADD = $(top_builddir)/src/libroman.la @CHECK_LIBS@
