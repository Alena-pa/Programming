#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Tree.c"
#include "Tests.c"

int main(void) {
    if (!allTests){
        printf("Tests failed!");
        return 1;
    }
}