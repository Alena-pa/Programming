#include <stdbool.h>
#include <stdio.h>
#include "test.h"

bool test() {
    char firstString[] = { "1 2 + 3 -" };
    char secondString[] = { "+ 1 2 - 3 +" };
    char thirdString[] = { "1 2 + 3 4" };
    int errorCode = 0;
    bool result = calculatePostfix(firstString, &errorCode) == 0 && calculatePostfix(secondString, &errorCode) == 1 && calculatePostfix(thirdString, &errorCode) == 1;
    printf("%d\n", errorCode);
    return result;
}