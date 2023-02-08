#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeCheck.h"
#include "GetRangeData.h"
#include "AdcConverter.h"

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
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 3\n") == 0);
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
  getRangeData(arrData, 7, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
  st_RangeCount outputRange = drivenRangeCheck(arrData,7);
  REQUIRE(outputRange.Count[0] == 4);
  REQUIRE(outputRange.Count[1] == 3);
  for(short i= 0;i<=outputRange.countSize;i++)
  {
    for(short j=0;j<outputRange.Count[i];j++)
    {
      REQUIRE(outputRange.OutArray[i][j] == arrData[k]);
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
  getRangeData(arrData, 7, output);
  REQUIRE(strcmp(output,"Range, Readings\n3-5, 4\n10, 1\n12, 1\n20, 1\n") == 0);
}


//Test case for ADC converter

TEST_CASE("Read 12 bit ADC value of 0-10 AMPS value") {
  int datacnt[]= {2000,3000};
  int OutputAmps[2];

  adcConverterReadValue(0,10,12,datacnt,2,OutputAmps);
  REQUIRE(OutputAmps[0]== 5);
  REQUIRE(OutputAmps[1]== 7);
}

TEST_CASE("Read 12 bit ADC value of 0-10 AMPS value with empty array count") {
  int datacnt[]= {};
  int OutputAmps[2] = {0,0};

  adcConverterReadValue(0,10,12,datacnt,0,OutputAmps);
  REQUIRE(OutputAmps[0]== 0);
}

TEST_CASE("Read 12 bit ADC value of 0-10 AMPS value with non valid array count") {
  int datacnt[]= {5000};
  int OutputAmps[2];

  adcConverterReadValue(0,10,12,datacnt,1,OutputAmps);
  REQUIRE(OutputAmps[0]== 0);
}