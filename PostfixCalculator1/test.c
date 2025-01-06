#include <stdbool.h>
#include <stdio.h>
#include "test.h"

bool test() {
    char firstString[] = { "1 2 + 3 -" };
    char secondString[] = { "+ 1 2 - 3 +" };
    char thirdString[] = { "1 2 + 3 4" };
    if (postfixCalculator(firstString) == 0 && postfixCalculator(secondString) == 1 && postfixCalculator(thirdString) == 1) {
        return true;
    }
    return false;
}