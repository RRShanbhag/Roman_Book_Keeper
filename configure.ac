# Process this file with autoconf to produce a configure script.

# place to put some extra build scripts installed
AC_CONFIG_AUX_DIR([build-aux])

# Prelude.
AC_PREREQ([2.59])
AC_INIT([Roman_Calculator], [1.0], [ranjit.shanbhag@gmail.com])
AM_PROG_AR

# unique source file --- primitive safety check 
AC_CONFIG_SRCDIR([src/roman_calculator.c])

#Declare directory to be the location of libtools
#LT_CONFIG_LTDL_DIR([/usr/share/libtool])

# place to put some extra build scripts installed
AC_CONFIG_AUX_DIR([build-aux])

# fairly severe build strictness
# change foreign to gnu or gnits to comply with gnu standards
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
PKG_CHECK_MODULES([CHECK], [check >= 0.9.6])
AM_PROG_CC_C_O

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

# Output files
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])

AC_SUBST(ac_aux_dir)
 
AC_OUTPUT
