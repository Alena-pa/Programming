#include <stdbool.h>
#include "binaryRepresentation.h"

bool test(void) {
    return (answer(1, 5) == 6 && answer(0, 0) == 0 && answer(1, 0) == 1 && answer(5, 5) == 10);
}