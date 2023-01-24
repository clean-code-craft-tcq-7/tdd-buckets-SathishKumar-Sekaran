#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeCheck.h"

TEST_CASE("Range readings checking with 2 array of data") {
  short arrData[] = {4,5};
  REQUIRE(drivenRangeCheck(arrData,2) == 2);
}

TEST_CASE("Range readings checking with 4 array of data with misalign array data") {
  short arrData[] = {3,5,4};
  REQUIRE(drivenRangeCheck(arrData,3) == 3);
}

TEST_CASE("Range readings checking with 5 array of data with Same value stored in array") {
  short arrData[] = {3,5,4,3};
  REQUIRE(drivenRangeCheck(arrData,4) == 4);
}
