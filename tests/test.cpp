#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"

std::string reversed(const std::string &in);

TEST_CASE( "Good Working test" ) {
	REQUIRE( reversed("abc") == "cba" );
}