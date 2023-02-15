#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "AdcConverter.h"

void testCases_ADC()
{
  // Read 12 bit ADC value of 0-10 AMPS value
  {
    int datacnt[]= {2000,3000};
    int OutputAmps[2];

    adcConverterReadValue(0,10,12,datacnt,2,OutputAmps);
    assert(OutputAmps[0]== 5);
    assert(OutputAmps[1]== 7);
  }
  // Read 12 bit ADC value of 0-10 AMPS value with empty array count
  {
      int datacnt1[]= {};
    int OutputAmps1[2] = {0,0};

    adcConverterReadValue(0,10,12,datacnt1,0,OutputAmps1);
    assert(OutputAmps1[0]== 0);
  }
  // Read 12 bit ADC value of 0-10 AMPS value with non valid array count
  {
    int datacnt2[]= {5000};
    int OutputAmps2[2];

    adcConverterReadValue(0,10,12,datacnt2,1,OutputAmps2);
    assert(OutputAmps2[0]== 0);
  }
  // Read 12 bit ADC value of 0-10 AMPS value with non valid  and vaild array count
  {
    int datacnt3[]= {5000, -3, 3005};
    int OutputAmps3[3];

    adcConverterReadValue(0,10,12,datacnt3,3,OutputAmps3);
    assert(OutputAmps3[0]== 0);
    assert(OutputAmps3[1]== 0);
    assert(OutputAmps3[2]== 7);
  }
  // Read 10 bit ADC value of 0-10 AMPS value
  {
    int datacnt4[]= {2000,3000,1000};
    int OutputAmps4[3];

    adcConverterReadValue(0,10,10,datacnt4,3,OutputAmps4);
    assert(OutputAmps4[0]== 0);
    assert(OutputAmps4[1]== 0);
    assert(OutputAmps4[2]== 10);
  }
  // Read 10 bit ADC value of -15 to 10 AMPS value
  {
    int datacnt5[]= {200,390,950};
    int OutputAmps5[3];

    adcConverterReadValue(-15,10,10,datacnt5,3,OutputAmps5);
    assert(OutputAmps5[0]== -10);
    assert(OutputAmps5[1]== -5);
    assert(OutputAmps5[2]== 8);
  }
  // Read 10 bit ADC value of -15 to 15 AMPS value
  {
    int datacnt6[]= {200,390,950};
    int OutputAmps6[3];

    adcConverterReadValue(-15,15,10,datacnt6,3,OutputAmps6);
    assert(OutputAmps6[0]== -9);
    assert(OutputAmps6[1]== -3);
    assert(OutputAmps6[2]== 13);
  }
}