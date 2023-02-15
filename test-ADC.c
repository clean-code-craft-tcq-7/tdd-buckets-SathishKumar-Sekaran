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
      int datacnt[]= {};
    int OutputAmps[2] = {0,0};

    adcConverterReadValue(0,10,12,datacnt,0,OutputAmps);
    assert(OutputAmps[0]== 0);
  }
  // Read 12 bit ADC value of 0-10 AMPS value with non valid array count
  {
    int datacnt[]= {5000};
    int OutputAmps[2];

    adcConverterReadValue(0,10,12,datacnt,1,OutputAmps);
    assert(OutputAmps[0]== 0);
  }
  // Read 12 bit ADC value of 0-10 AMPS value with non valid  and vaild array count
  {
    int datacnt[]= {5000, -3, 3005};
    int OutputAmps[3];

    adcConverterReadValue(0,10,12,datacnt,3,OutputAmps);
    assert(OutputAmps[0]== 0);
    assert(OutputAmps[1]== 0);
    assert(OutputAmps[2]== 7);
  }
  // Read 10 bit ADC value of 0-10 AMPS value
  {
    int datacnt[]= {2000,3000,1000};
    int OutputAmps[3];

    adcConverterReadValue(0,10,10,datacnt,3,OutputAmps);
    assert(OutputAmps[0]== 0);
    assert(OutputAmps[1]== 0);
    assert(OutputAmps[2]== 10);
  }
  // Read 10 bit ADC value of -15 to 10 AMPS value
  {
    int datacnt[]= {200,390,950};
    int OutputAmps[3];

    adcConverterReadValue(-15,10,10,datacnt,3,OutputAmps);
    assert(OutputAmps[0]== -10);
    assert(OutputAmps[1]== -5);
    assert(OutputAmps[2]== 8);
  }
  // Read 10 bit ADC value of -15 to 15 AMPS value
  {
    int datacnt[]= {200,390,950};
    int OutputAmps[3];

    adcConverterReadValue(-15,15,10,datacnt,3,OutputAmps);
    assert(OutputAmps[0]== -9);
    assert(OutputAmps[1]== -3);
    assert(OutputAmps[2]== 13);
  }
  // ADC converter data with range check
  {
    int datacnt[]= {1200, 1228, 2047, 1637};
    int OutputAmps[4];
    char output[100];
    short arrayAmps[4];
    int i=0;
    memset(output, 0, 100);

    adcConverterReadValue(0,10,12,datacnt,4,(int*)OutputAmps);
    assert(OutputAmps[0]== 3);
    assert(OutputAmps[1]== 3);
    assert(OutputAmps[2]== 5);
    assert(OutputAmps[3]== 4);
    while(i<4)
    {
      arrayAmps[i] = (short)OutputAmps[i];
      i++;
    }
    getRangeData(arrayAmps, 4, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n") == 0);
  }
}