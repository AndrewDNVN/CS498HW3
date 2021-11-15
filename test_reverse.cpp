#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <cstring>

//Given
std::string reversed(const std::string &in)
{
    std::string out{};
    out.reserve(in.length());
    for (auto i = in.rbegin(); i != in.rend(); ++i) {
        out += *i;
    }
    return out;
}

// uncomment for submission
//std::string reversed(const std::string &in);

TEST_CASE( "Single char:" "[Single]" ) {
    REQUIRE( reversed("a") == "a");

    REQUIRE( reversed("A") == "A");

    REQUIRE( reversed(" ") == " "); // spaces should be unaffected
}

TEST_CASE( "Simple tests:" "[Small]" ) {
    REQUIRE( reversed("abc") == "cba");

    REQUIRE( reversed("123") == "321");
}




    // Another point of intrest with catch2
    // is when in a test case when one Require 
    // fails it just moves onto the next block.
    // Which is strange to me; I feel it should test 
    // no matter if one has failed.
    // Or at least acknowledge that the 
    // other states in the block.





TEST_CASE( "Even number tests:" ) {
    REQUIRE( reversed("abcd") == "dcba");


    REQUIRE( reversed("1234") == "4321");
}


TEST_CASE( "Same word [Palindrome]:" ) {
    REQUIRE( reversed("bob") == "bob");

    //should fail
    REQUIRE( reversed("racecar") == "racecar");
}


// Suspected Bouns testing fail case:
// passing a null char.

TEST_CASE( "Bouns:" "[bouns]" ) {

    std::string in = "ab\0cd";
    std::string out = "dc\0ba";

    REQUIRE( reversed(in) == out);
}


//    The above should fail becuase it is a hold over from
//    C where that '\0' marked the end of the char array.
//    So in this case it stops the string from reading beyond.
//    That is why it fails the Test case.

