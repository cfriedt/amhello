#include <string>

#include <gtest/gtest.h>

extern "C" {
char *greeting();
}

TEST(HelloTest, hi) {
	std::string expected_str = "Hello, world!";
	std::string actual_str = std::string( greeting() );

	EXPECT_EQ( expected_str, actual_str )
		<< "strings "
		<< "'" << expected_str << "'"
		<< " and "
		<< "'" << actual_str << "'"
		<< " do not match"
	;
}

TEST(HelloTest, hi) {
	std::string expected_str = "Sayonara!";
	std::string actual_str = std::string( greeting() );

	EXPECT_EQ( expected_str, actual_str )
		<< "strings "
		<< "'" << expected_str << "'"
		<< " and "
		<< "'" << actual_str << "'"
		<< " do not match"
	;
}
