#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include "list.h"

bool test() {
    return count(10, 2) == 5 && count(10, 3) == 4 && count(10, 8) == 1 && count(1, 3) == 1 && count(5, 6) == 4;
}
