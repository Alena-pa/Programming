#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MostCommonElement.h"

int maxArray(int* arrayOfIntegers, int lengthOfArray) {
    int maxInteger = arrayOfIntegers[0];
    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] > maxInteger) {
            maxInteger = arrayOfIntegers[i];
        }
    }
    return maxInteger;
}

int minArray(int* arrayOfIntegers, int lengthOfArray) {
    int minInteger = arrayOfIntegers[0];
    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] < minInteger) {
            minInteger = arrayOfIntegers[i];
        }
    }
    return minInteger;
}

int mostCommonElement(int* arrayOfIntegers, int lengthOfArray) {
    int maxInteger = maxArray(arrayOfIntegers, lengthOfArray);
    int minInteger = minArray(arrayOfIntegers, lengthOfArray);
    int* countArray = (int*)calloc(maxInteger - minInteger + 1, sizeof(int));
    if (countArray == NULL) {
        printf("Memory Allocation!");
        return -1;
    }

    for (int i = 0; i < lengthOfArray; i++) {
        countArray[arrayOfIntegers[i] - minInteger]++;
    }

    int maxCommonNum = 0;
    int mostCommon = 0;
    for (int i = 0; i < lengthOfArray; i++) {
        if (countArray[i] > mostCommon) {
            mostCommon = countArray[i];
            maxCommonNum = i;
        }
    }

    free(countArray);
    return maxCommonNum;
}

bool test() {
    int arrayOfIntegers[5] = { 1, 2, 2, 3, 4 };
    int anotherArrayOfIntegers[5] = { 0, 0, 2, 3, 3 };
    return mostCommonElement(arrayOfIntegers, 5) == 2 && (mostCommonElement(anotherArrayOfIntegers, 5) == 0 || mostCommonElement(anotherArrayOfIntegers, 5) == 3);
}
