#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeCheck.h"

TEST_CASE("Range readings checking with 2 array of data") {
  short arrData[] = {4,5};
  REQUIRE(drivenRangeCheck(arrData,2).Count[0] == 2);
}

TEST_CASE("Range readings checking with 4 array of data with misalign array data") {
  short arrData[] = {3,5,4};
  REQUIRE(drivenRangeCheck(arrData,3).Count[0] == 3);
}

TEST_CASE("Range readings checking with 5 array of data with Same value stored in array") {
  short arrData[] = {3,5,4,3};
  REQUIRE(drivenRangeCheck(arrData,4).Count[0] == 4);
}

TEST_CASE("Range readings checking with 7 array of data with multiple range checks") {
  short arrData[] = {3,3,5,4,10,11,12};
  short k = 0;
  st_RangeCount output = drivenRangeCheck(arrData,7);
  REQUIRE(output.Count[0] == 4);
  REQUIRE(output.Count[1] == 3);
  for(short i= 0;i<output.countSize;i++)
  {
    for(short j=0;j<output.Count[i];j++)
    {
      REQUIRE(output.OutArray[i][j] == arrData[k]);
      k++;
    }
  }
}