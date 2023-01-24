#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeCheck.h"

TEST_CASE("Range readings checking") {
  short arrData[] = {4,5};
  REQUIRE(drivenRangeCheck(arrData,2) == 2);
}
