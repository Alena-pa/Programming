#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include "postfixCalculator.h"

bool test() {
    char firstString[] = { "1 2 + 3 -" };
    int errorCode = 0;
    return calculatePostfix(firstString, &errorCode) == 0;
}