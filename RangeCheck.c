#include <stdio.h>
#include "RangeCheck.h"

short drivenRangeCheck(const short* ArrData,short arrSize)
{
    short i =0;
    short readRangeCnt =1;
    sortInAscending(ArrData,arrSize);
    while((i+1)<arrSize)
    {
        if((ArrData[i]+1) == ArrData[i+1])
        {
            readRangeCnt++;
        }
        i++;
    }
    return readRangeCnt;
}

void sortInAscending(int* ArrData, int arrSize)
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