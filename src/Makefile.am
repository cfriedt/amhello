bin_PROGRAMS = hello
hello_SOURCES = main.c
hello_LDADD = libhello.la

lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = hello.c
libhello_la_LDFLAGS = -release $(PACKAGE_VERSION)

#if HAVE_GTEST

tests =

test_hello_SOURCES = test_hello.cpp
test_hello_CPPFLAGS = @GTEST_CPPFLAGS@
test_hello_LDFLAGS = @GTEST_LDFLAGS@
test_hello_LDADD = libhello.la @GTEST_LIBS@

tests += test_hello

noinst_PROGRAMS = \
  test_hello

.PHONY: check

check-local: $(tests)
	for i in $(tests); do \
		./$$i --gtest_output=xml:$(builddir)/$$i.xml || true; \
	done

#endif

include_HEADERS = hello.h
