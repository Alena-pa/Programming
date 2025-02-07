#include <stdio.h>
#include <stdbool.h>
#include "test.h"
#include "MostCommonElement.h"

bool test(void) {
    int arrayOfIntegers[5] = { 1, 2, 2, 3, 4 };
    int anotherArrayOfIntegers[5] = { 0, 0, 2, 3, 3 };
    return mostCommonElement(arrayOfIntegers, 5) == 2 && (mostCommonElement(anotherArrayOfIntegers, 5) == 0 || mostCommonElement(anotherArrayOfIntegers, 5) == 3);
}