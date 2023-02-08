#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "AdcConverter.h"

TEST_CASE("Read 12 bit ADC value of 0-10 AMPS value") {
  int datacnt[]= {2000,3000};
  int OutputAmps[2];

  adcConverterReadValue(0,10,12,datacnt,2,OutputAmps);
  REQUIRE(OutputAmps[0]== 5);
  REQUIRE(OutputAmps[1]== 7);
}
