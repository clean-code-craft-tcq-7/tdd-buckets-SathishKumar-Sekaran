#include <stdio.h>
#include <stdlib.h>
#include "test-ADC.h"
#include "test-alert.h"
#include "test-RangeproviderWithADC.h"

int main(int argc, char* argv[])
{
    testCases_Alerts();
    testCases_ADC();
    test_RangeproviderWithADC();
}