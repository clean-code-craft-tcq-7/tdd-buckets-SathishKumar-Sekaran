#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "AdcConverter.h"
#include "RangeCheck.h"
#include "GetRangeData.h"
#include "test-RangeproviderWithADC.h"

void test_RangeproviderWithADC()
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