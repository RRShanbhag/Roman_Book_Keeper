## Process this file with automake to produce Makefile.in

TESTS = roman_dec
check_PROGRAMS = roman_dec
roman_dec_SOURCES = roman_dec.c $(top_builddir)/src/roman.h
roman_dec_CFLAGS = @CHECK_CFLAGS@
roman_dec_LDADD = $(top_builddir)/src/libroman.la @CHECK_LIBS@
