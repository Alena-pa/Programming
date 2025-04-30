#include "MostCommonElement.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (!test()) {
        printf("Snth Went Wrong!!!!!!!!!!!");
        return -1;
    }

    FILE* file = fopen("inputFile.txt", "r");
    int* array = malloc(sizeof(int) * 100);
    int lengthOfArray = 0;
    for (int i = 0; file != EOF; i++) {
        fscanf(file, "%d", &array[i]);
        lengthOfArray++;
    }

    mostCommonElement(array, lengthOfArray);
}