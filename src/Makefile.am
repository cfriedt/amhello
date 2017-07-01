bin_PROGRAMS = hello
hello_SOURCES = main.c
hello_LDADD = libhello.la

lib_LTLIBRARIES = libhello.la
libhello_la_SOURCES = hello.c
libhello_la_LDFLAGS = -release $(PACKAGE_VERSION)

#if HAVE_GTEST

test_hello_SOURCES = test_hello.cpp
test_hello_CPPFLAGS = @GTEST_CPPFLAGS@
test_hello_LDFLAGS = @GTEST_LDFLAGS@
test_hello_LDADD = libhello.la @GTEST_LIBS@

TESTS = test_hello

noinst_PROGRAMS = \
  test_hello

.PHONY: check

check: $(TESTS)
	for i in $(TESTS); do \
		./$$i --gtest_output=xml:`pwd`:$$i.xml || true; \
	done

#endif

include_HEADERS = hello.h
