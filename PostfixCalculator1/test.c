#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include "postfixCalculator.h"

bool test(void) {
    char firstString[] = { "1 2 + 3 -" };
    int errorCode = 0;
    int result = calculatePostfix(firstString, &errorCode);
    if (errorCode != 0) { 
        printf("error code: %d\n", errorCode);
    }
    return result == 0;
}