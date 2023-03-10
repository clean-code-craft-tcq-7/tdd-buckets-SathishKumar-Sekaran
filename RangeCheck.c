#include <stdio.h>
#include "RangeCheck.h"

st_RangeCount drivenRangeCheck(short* ArrData,short arrSize)
{
    short i =0;
    short j =0;
    short k =0;
    st_RangeCount readRangeCnt;
    sortInAscending(ArrData,arrSize);
    readRangeCnt.Count[j] = 1;
    readRangeCnt.OutArray[j][i] = ArrData[i];
    k=++i;
    while(i<arrSize)
    {
        if(((ArrData[i-1]+1) == ArrData[i]) || ((ArrData[i]) == ArrData[i-1]))
        {
            readRangeCnt.Count[j] += 1;
            readRangeCnt.OutArray[j][k] = ArrData[i];
        }
        else
        { 
            j++;
            k=0;
            readRangeCnt.Count[j] = 1;
            readRangeCnt.OutArray[j][k] = ArrData[i];
        }
        i++;
        k++;
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