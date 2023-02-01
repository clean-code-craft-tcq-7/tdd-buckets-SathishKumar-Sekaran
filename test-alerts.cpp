#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeCheck.h"

TEST_CASE("Range readings checking with 2 array of data") {
  char output[100];
  memset(output, 0, 100);

  short arrData[] = {4,5};
  getRangeData(arrData, 2, output);
  REQUIRE(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
  REQUIRE(drivenRangeCheck(arrData,2).Count[0] == 2);
}

TEST_CASE("Range readings checking with 4 array of data with misalign array data") {
  char output[100];
  memset(output, 0, 100);
  short arrData[] = {3,5,4};
  getRangeData(arrData, 3, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 2\n") == 0);
  REQUIRE(drivenRangeCheck(arrData,3).Count[0] == 3);
}

TEST_CASE("Range readings checking with 5 array of data with Same value stored in array") {
  char output[100];
  memset(output, 0, 100);
  short arrData[] = {3,5,4,3};
  getRangeData(arrData, 4, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 4\n") == 0);
  REQUIRE(drivenRangeCheck(arrData,4).Count[0] == 4);
}

TEST_CASE("Range readings checking with 7 array of data with multiple range checks") {
  char output[100];
  memset(output, 0, 100);
  short arrData[] = {3,3,5,4,10,11,12};
  short k = 0;
  getRangeData(arrData, 2, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
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

TEST_CASE("Range readings checking with Empty array with invaild array size") {
  char output[100];
  memset(output, 0, 100);
  getRangeData(NULL, 0, output);
  REQUIRE(strcmp(output,"Range, Readings\n") == 0);
}

TEST_CASE("Range readings checking with Empty array with Vaild array") {
  char output[100];
  memset(output, 0, 100);
  short arrData[2];
  getRangeData(arrData, 2, output);
  REQUIRE(strcmp(output,"Range, Readings\n") == 0);
}

TEST_CASE("Range readings checking with Empty array of data") {
  char output[100];
  memset(output, 0, 100);
  short arrData[2];
  getRangeData(arrData, 0, output);
  REQUIRE(strcmp(output,"Range, Readings\n") == 0);
}

TEST_CASE("Range readings checking with single array of data") {
  char output[100];
  memset(output, 0, 100);

  short arrData[] = {5};
  getRangeData(arrData, 1, output);
  REQUIRE(strcmp(output,"Range, Readings\n5, 1\n") == 0);
}

TEST_CASE("Range readings checking with 7 array and one range value") {
  char output[100];
  memset(output, 0, 100);
  short arrData[] = {3,3,5,4,10,20,12};
  short k = 0;
  getRangeData(arrData, 2, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 4\n10, 1\n12, 1\n20, 1\n") == 0);
}
