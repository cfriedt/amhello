#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([amhello], [1.0], [bug-report@address])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AM_PROG_AR
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([puts])

# Check for libgtest
dnl XXX: @CF: fix gtest-config and gtest.m4
dnl GTEST_LIB_CHECK([1.7.0])
GTEST_CPPFLAGS="-I/usr/local/include"
AC_SUBST([GTEST_CPPFLAGS])
GTEST_LDFLAGS="-L/usr/local/lib"
AC_SUBST([GTEST_LDFLAGS])
GTEST_LIBS="-lgtest -lgtest_main"
AC_SUBST([GTEST_LIBS])
AM_CONDITIONAL([HAVE_GTEST],[test "x$enable_gtest" = "xyes"])


# Output files.
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([ Makefile
                  src/Makefile 
                  support/Makefile
                  support/amhello-config
                  ])
AC_OUTPUT
