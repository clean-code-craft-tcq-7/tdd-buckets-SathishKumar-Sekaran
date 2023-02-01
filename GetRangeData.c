#include <stdio.h>
#include <string.h>
#include "RangeCheck.h"

void getRangeData(short* ArrData, short ArrSize, char* buff)
{
    char printData[200];
    st_RangeCount readRangeData;

    memset(printData, 0, 200);

    sprintf(printData,"%s\n",HEADER_CHAR);
    if((ArrData != NULL) && (ArrSize > 0))
    {
        readRangeData = drivenRangeCheck(ArrData,ArrSize);
        ConvertRangeOutString(readRangeData,&printData[strlen(HEADER_CHAR) + 1]);
    }
    strncpy(buff,printData,strlen(printData));
}

void ConvertRangeOutString(st_RangeCount readRangeData,char* strVal)
{
    char rangeInfo[20];
    short i =0, j=0;

    while(i < readRangeData.countSize)
    {
        memset(rangeInfo,0,20);
        sprintf(rangeInfo,"%d-%d, %d\n", readRangeData.OutArray[0], readRangeData.OutArray[readRangeData.Count[i]-1], readRangeData.Count[i]);
        strncpy(strVal,rangeInfo,strlen(rangeInfo));
        strVal += strlen(rangeInfo);
    }
}