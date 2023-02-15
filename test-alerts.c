#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "RangeCheck.h"
#include "GetRangeData.h"

void testCases_Alerts()
{
  char output[100];
  //Range readings checking with 2 array of data
  {
    memset(output, 0, 100);

    short arrData[] = {4,5};
    getRangeData(arrData, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
  }
  // Range readings checking with 4 array of data with misalign array data
  {
    memset(output, 0, 100);
    short arrData1[] = {3,5,4};
    getRangeData(arrData1, 3, output);
    assert(strcmp(output,"Range, Readings\n3-5, 3\n") == 0);
    assert(drivenRangeCheck(arrData1,3).Count[0] == 3);
  }
  // Range readings checking with 5 array of data with Same value stored in array
  {
    memset(output, 0, 100);
    short arrData2[] = {3,5,4,3};
    getRangeData(arrData2, 4, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n") == 0);
    assert(drivenRangeCheck(arrData2,4).Count[0] == 4);
  }
  // Range readings checking with 7 array of data with multiple range checks
  {
    memset(output, 0, 100);
    short arrData3[] = {3,3,5,4,10,11,12};
    short k = 0;
    getRangeData(arrData3, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
    st_RangeCount outputRange = drivenRangeCheck(arrData3,7);
    assert(outputRange.Count[0] == 4);
    assert(outputRange.Count[1] == 3);
    for(short i= 0;i<=outputRange.countSize;i++)
    {
      for(short j=0;j<outputRange.Count[i];j++)
      {
        assert(outputRange.OutArray[i][j] == arrData3[k]);
        k++;
      }
    }
  }
  // Range readings checking with 7 array of data with multiple range checks
  {
    memset(output, 0, 100);
    short arrData4[] = {3,3,5,4,10,11,12};
    short k1 = 0;
    getRangeData(arrData4, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
    st_RangeCount outputRange = drivenRangeCheck(arrData4,7);
    assert(outputRange.Count[0] == 4);
    assert(outputRange.Count[1] == 3);
    for(short i= 0;i<=outputRange.countSize;i++)
    {
      for(short j=0;j<outputRange.Count[i];j++)
      {
        assert(outputRange.OutArray[i][j] == arrData4[k1]);
        k1++;
      }
    }
  }
  // Range readings checking with Empty array with invaild array size
  {
    memset(output, 0, 100);
    getRangeData(NULL, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);
  }
  //Range readings checking with Empty array of data
  {
    memset(output, 0, 100);
    short arrData5[2];
    getRangeData(arrData5, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);
  }
  // Range readings checking with single array of data
  {
    memset(output, 0, 100);

    short arrData6[] = {5};
    getRangeData(arrData6, 1, output);
    assert(strcmp(output,"Range, Readings\n5, 1\n") == 0);
  }
  // Range readings checking with 7 array and one range value
  {
    memset(output, 0, 100);
    short arrData7[] = {3,3,5,4,10,20,12};
    getRangeData(arrData7, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10, 1\n12, 1\n20, 1\n") == 0);
  }
}
