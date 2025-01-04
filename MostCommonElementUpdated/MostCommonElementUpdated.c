#include <stdio.h>
#include <stdlib.h>
#include "MostCommonElement.h"

int mostCommonElement(int* arrayOfIntegers, int lengthOfArray) {
    int maxInteger = maxArray(arrayOfIntegers, lengthOfArray);
    int* countArray = (int*)calloc(maxInteger + 1, sizeof(int));
    for (int i = 0; i < lengthOfArray; i++) {
        countArray[arrayOfIntegers[i]]++;
    }
    int maxCommonNum = 0;
    int mostCommon = 0;
    for (int i = 0; i < maxInteger + 1; i++) {
        if (countArray[i] > mostCommon) {
            mostCommon = countArray[i];
            maxCommonNum = i;
        }
    }
    return maxCommonNum;
}

int maxArray(int* arrayOfIntegers, int lengthOfArray) {
    int maxInteger = 0;
    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] > maxInteger) {
            maxInteger = arrayOfIntegers[i];
        }
    }
    return maxInteger;
}
