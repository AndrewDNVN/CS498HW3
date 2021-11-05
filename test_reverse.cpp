#define CATCH_CONFIG_MAIN
#include <string>
#include<algorithm>
#include<cstring>
#include "catch.hpp"

std::string reversed(const std::string &in)
{
    std::string out{};
    out.reserve(in.length());
    for (auto i = in.rbegin(); i != in.rend(); ++i) {
        out += *i;
    }
    return out;
}

TEST_CASE( "An empty string returns an empty string" ) {
	REQUIRE( reversed("") == "");
}

TEST_CASE( "A single character returns the same character" ) {
	REQUIRE( reversed("a") == "a"); //Lowercase
	REQUIRE( reversed("A") == "A" ); //Uppercase
	REQUIRE( reversed(" ") == " " );
}

TEST_CASE("A string of all the same characters stays the same"){
    REQUIRE( reversed("aaa") == "aaa"); //Odd number of characters
    REQUIRE( reversed("XX") == "XX"); //Even number of characters
    REQUIRE( reversed("   ") == "   "); //Multiple spaces
    REQUIRE( reversed("ffffffffff") == "ffffffffff"); //Lots of characters
}

TEST_CASE("Palindromes return the same word"){
    REQUIRE( reversed("bob") == "bob"); //lowercase short
    REQUIRE( reversed("racecar") == "racecar"); //longer palindrome
    REQUIRE( reversed("Anna") == "annA"); //Capitalized
}

TEST_CASE("Words with odd number of characters"){
    REQUIRE( reversed("cat") == "tac"); //Lowercase 3 chars
    REQUIRE( reversed("jiffy") == "yffij"); //Lowercase 5 chars
    REQUIRE( reversed("lackadaisical") == "lacisiadakcal"); //Lowercase 13 characters
    REQUIRE( reversed("JUNKY") == "YKNUJ"); //Uppercase 5 chars
}

TEST_CASE("Words with even number of characters"){
    REQUIRE( reversed("at") == "ta"); //Lowercase 2 chars
    REQUIRE( reversed("baby") == "ybab"); //Lowercase 4 chars
    REQUIRE( reversed("photosynthesis") == "sisehtnysotohp"); //Lowercase 14 characters
    REQUIRE( reversed("SIZZLE") == "ELZZIS"); //Uppercase 6 chars
}

TEST_CASE("Strings with mix of uppercase and lowercase"){
    REQUIRE( reversed("AbCdE") == "EdCbA"); //Odd number of chars
    REQUIRE( reversed("qWErtY") == "YtrEWq"); //Even number of chars
}

TEST_CASE("A sentence with spaces"){
    REQUIRE( reversed("This is a sentence.") == ".ecnetnes a si sihT");
}

TEST_CASE("Strings with special characters"){
    REQUIRE( reversed("a\\b%cd!") == "!dc%b\\a");
    REQUIRE( reversed("abc\nd") == "d\ncba"); //newline
    REQUIRE( reversed("\n\v\t\r") == "\r\t\v\n"); //only special chars
    //The test below is testing the use of the null character
    //In a typical c-string, it ends at the null character but a cpp string
    //should be able to contain a null character
    using namespace std::string_literals;
    std::string test = "ab\0cd"s;
    std::string result = "dc\0ba"s;
    REQUIRE( reversed(test) == result);
}