
#define HEADER_CHAR  "Range, Readings"
typedef struct
{
    short Count[100];
    short OutArray[100][100];
    short countSize;
}st_RangeCount;

st_RangeCount drivenRangeCheck(short* ArrData,short arrSize);
void sortInAscending(short* ArrData, short arrSize);