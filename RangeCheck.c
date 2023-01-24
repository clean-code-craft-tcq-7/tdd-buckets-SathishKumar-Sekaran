#include <stdio.h>
#include "RangeCheck.h"

st_RangeCount drivenRangeCheck(short* ArrData,short arrSize)
{
    short i =0;
    short j =0;
    st_RangeCount readRangeCnt;
    sortInAscending(ArrData,arrSize);
    readRangeCnt.Count[j] = 1;
    readRangeCnt.OutArray[i][j] = ArrData[i];
    while((i+1)<arrSize)
    {
        if(((ArrData[i]+1) == ArrData[i+1]) || ((ArrData[i]) == ArrData[i+1]))
        {
            readRangeCnt.Count[j] += 1;
            readRangeCnt.OutArray[i][j] = ArrData[i+1];
        }
        else
        {
            j++;
            readRangeCnt.Count[j] = 1;
            readRangeCnt.OutArray[i][j] = ArrData[i];
        }
        i++;
    }
    readRangeCnt.countSize = j;
    return readRangeCnt;
}

void sortInAscending(short* ArrData, short arrSize)
{
    int temp,i,j;

    for(i = 0; i < arrSize; i++)
    {
        for(j = i + 1; j < arrSize; j++)
        {
            if(ArrData[i] > ArrData[j])
            {
                temp = ArrData[i];
                ArrData[i] = ArrData[j];
                ArrData[j] = temp;
            }
        }
    }
}