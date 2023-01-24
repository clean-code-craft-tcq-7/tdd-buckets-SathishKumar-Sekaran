#include <stdio.h>
#include "RangeCheck.h"

short drivenRangeCheck(const short* ArrData,short arrSize)
{
    short i =0;
    short j =1;
    short readRangeCnt =1;
    while(j<arrSize)
    {
        if((ArrData[i]+1) == ArrData[j])
        {
            readRangeCnt++;
        }
        i++;
        j++;
    }
}