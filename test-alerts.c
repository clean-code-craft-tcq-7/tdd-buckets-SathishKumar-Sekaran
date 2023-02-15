#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "RangeCheck.h"
#include "GetRangeData.h"

void testCases_Alerts()
{
  //Range readings checking with 2 array of data
  {
    char output[100];
    memset(output, 0, 100);

    short arrData[] = {4,5};
    getRangeData(arrData, 2, output);
    assert(strcmp(output,"Range, Readings\n4-5, 2\n") == 0);
  }
  // Range readings checking with 4 array of data with misalign array data
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[] = {3,5,4};
    getRangeData(arrData, 3, output);
    assert(strcmp(output,"Range, Readings\n3-5, 3\n") == 0);
    assert(drivenRangeCheck(arrData,3).Count[0] == 3);
  }
  // Range readings checking with 5 array of data with Same value stored in array
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[] = {3,5,4,3};
    getRangeData(arrData, 4, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n") == 0);
    assert(drivenRangeCheck(arrData,4).Count[0] == 4);
  }
  // Range readings checking with 7 array of data with multiple range checks
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[] = {3,3,5,4,10,11,12};
    short k = 0;
    getRangeData(arrData, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
    st_RangeCount outputRange = drivenRangeCheck(arrData,7);
    assert(outputRange.Count[0] == 4);
    assert(outputRange.Count[1] == 3);
    for(short i= 0;i<=outputRange.countSize;i++)
    {
      for(short j=0;j<outputRange.Count[i];j++)
      {
        assert(outputRange.OutArray[i][j] == arrData[k]);
        k++;
      }
    }
  }
  // Range readings checking with 7 array of data with multiple range checks
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[] = {3,3,5,4,10,11,12};
    short k = 0;
    getRangeData(arrData, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10-12, 3\n") == 0);
    st_RangeCount outputRange = drivenRangeCheck(arrData,7);
    assert(outputRange.Count[0] == 4);
    assert(outputRange.Count[1] == 3);
    for(short i= 0;i<=outputRange.countSize;i++)
    {
      for(short j=0;j<outputRange.Count[i];j++)
      {
        assert(outputRange.OutArray[i][j] == arrData[k]);
        k++;
      }
    }
  }
  // Range readings checking with Empty array with invaild array size
  {
    char output[100];
    memset(output, 0, 100);
    getRangeData(NULL, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);
  }
  //Range readings checking with Empty array of data
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[2];
    getRangeData(arrData, 0, output);
    assert(strcmp(output,"Range, Readings\n") == 0);
  }
  // Range readings checking with single array of data
  {
    char output[100];
    memset(output, 0, 100);

    short arrData[] = {5};
    getRangeData(arrData, 1, output);
    assert(strcmp(output,"Range, Readings\n5, 1\n") == 0);
  }
  // Range readings checking with 7 array and one range value
  {
    char output[100];
    memset(output, 0, 100);
    short arrData[] = {3,3,5,4,10,20,12};
    getRangeData(arrData, 7, output);
    assert(strcmp(output,"Range, Readings\n3-5, 4\n10, 1\n12, 1\n20, 1\n") == 0);
  }
}
