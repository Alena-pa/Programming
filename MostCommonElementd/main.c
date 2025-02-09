#include "MostCommonElement.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (!test()) {
        printf("test failed");
        return -1;
    }

    FILE* file = fopen("inputFile.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return -1;
    }

    fclose(file);
    int* array = malloc(sizeof(int) * 100);
    if (array == NULL) {
        printf("Memory allocation!");
        return -1;
    }
    int lengthOfArray = 0;

    while (lengthOfArray < 100 && fscanf(file, "%d", &array[lengthOfArray]) == 1) {
        lengthOfArray++;
    }

    if (lengthOfArray <= 0) {
        printf("array is empty");
        return -1;
    }
    int element = mostCommonElement(array, lengthOfArray);

    free(array);
    printf("mostCommonElement: %d\n", element);
}