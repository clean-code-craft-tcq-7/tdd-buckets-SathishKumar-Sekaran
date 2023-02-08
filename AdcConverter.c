#include <stdio.h>
#include "AdcConverter.h"

int PowerOf2(int bitRate)
{
    int returnVal = 1;
    while(bitRate > 0)
    {
        returnVal *=2;
        bitRate--;
    }
    return returnVal;
}

int roundOfVal(float floatVal)
{
    int Intval = (int)floatVal;
    float roundVal = floatVal - (float)Intval;
    if(roundVal > 0.5)
    {
        return (int)(floatVal+0.5);
    }
    else
    {
        return Intval;
    }
}

void adcConverterReadValue(int minRange,int maxRange,int adcBitRate,int* DataCount,int DataLen,int* outputAmps)
{
    int Max_differentVal_Amps = maxRange - minRange;
    float out[DataLen];
    int loopcnt = 0;
    while(loopcnt<DataLen)
    {
        out[loopcnt] = (float)Max_differentVal_Amps *(float)((float)DataCount[loopcnt]/(float)PowerOf2(adcBitRate));
        out[loopcnt] += minRange;
        outputAmps[loopcnt] = roundOfVal(out[loopcnt]);
        loopcnt++;
    }
}