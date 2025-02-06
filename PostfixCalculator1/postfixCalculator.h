#pragma once
#include <stdbool.h>
#include "stack.h"

// calculating an arithmetic expression in postfix form
int calculatePostfix(const char* string, int* errorCode);