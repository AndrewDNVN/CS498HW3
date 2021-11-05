#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <cstring>


std::string reversed(const std::string &in)
{
    std::string out{};
    out.reserve(in.length());
    for (auto i = in.rbegin(); i != in.rend(); ++i) {
        out += *i;
    }
    return out;
}

TEST_CASE( "Simple tests 1 works 2 does not:" ) {
    REQUIRE( reversed("abc") == "cba");

    //should fail
    REQUIRE( reversed("abc") == "abc");
}

