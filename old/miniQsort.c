#include <stdio.h>
#include <stdlib.h>

void swap(int *left, int *right) {
    if (left == right) {
        return;
    }
    
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void randomise(int *arrayOfIntegers, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        arrayOfIntegers[i] = rand() % 10;
    }
}


void printArray(int* arrayOfIntegers, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        printf("%d ", arrayOfIntegers[i]);
    }
    printf("\n");
}

void sortingArrayOfIntegers(int *arrayOfIntegers, int lengthOfArray) {
    int lastChangedIndex = 0;
    int indexOfFirstElement = 0;
    if (arrayOfIntegers[0] == 0) {
        return;
    }

    for (int i = 1; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] < arrayOfIntegers[0]) {
            swap(&arrayOfIntegers[indexOfFirstElement], &arrayOfIntegers[indexOfFirstElement++]);
            swap(&arrayOfIntegers[i], &arrayOfIntegers[lastChangedIndex]);
            lastChangedIndex++;
            printArray(arrayOfIntegers, lengthOfArray);
        }
    }
}


int main()
{
	int arrayOfIntegers[10] = { 0 };
    randomise(arrayOfIntegers, 10);
    printArray(arrayOfIntegers, 10);
    printf("\n");
    sortingArrayOfIntegers(arrayOfIntegers, 10);
    //printArray(arrayOfIntegers, 10);
}
