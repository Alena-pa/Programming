#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int* left, int* right) {
    int justVar = *right;
    if (left != right) {
        *right = *left;
        *left = justVar;
    }
}

void bubbleSort(int *arrayOfIntegers, int lenghtOfArray) {
    for (int i = 0; i < lenghtOfArray - 1; i++) {
        bool isSorted = true;
        for (int j = 0; j < lenghtOfArray - i - 1; j++)  {
            if (arrayOfIntegers[j] > arrayOfIntegers[j + 1]) {
                swap(&arrayOfIntegers[j], &arrayOfIntegers[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted == true) {
            break;
        }
    }
}

int maxArray(int * arrayOfIntegers, int lengthOfArray) {
    int maxInteger = 0;
    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] > maxInteger) {
            maxInteger = arrayOfIntegers[i];
        }
    }
    return maxInteger;
}

int minArray(int *arrayOfIntegers, int lengthOfArray) {
    int minInteger = 10000;
    for (int i = 0; i < lengthOfArray; i++ ) {
        if (arrayOfIntegers[i] < minInteger) {
            minInteger = arrayOfIntegers[i];
        }
    }
    return minInteger;
}

bool countSort(int *arrayOfIntegers, int lengthOfArray) {
    int maxInteger = maxArray(arrayOfIntegers, lengthOfArray);

    int countArraySize = maxInteger * 2 + 1;
    int* countArray = (int*)calloc(countArraySize, sizeof(int));
    if(!countArray) {
        printf("Memory allocation!");
        return false;
    }

    for (int i = 0; i < lengthOfArray; i++) {
        countArray[arrayOfIntegers[i] + maxInteger]++;
    }
    

    int i = 0;
    for (int j = 0; j < countArraySize; j++) {
        while (countArray[j] > 0) {
            arrayOfIntegers[i] = j - maxInteger;
            countArray[j]--;
            i++;
        }
    }

    free(countArray);
    return true;
}

void printArray(int* arrayOfIntegers, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

bool areEqual(int *firstArray, int *secondArray, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        if (firstArray[i] != secondArray[i]) {
            return false;
        }
    }
    return true;
}

bool testCountSort(void) {
    int unsortedArray[5] = { 3, -2, 5, 0, -1};
    int expectedArray[5] = { -2, -1, 0, 3, 5 };
    countSort(unsortedArray, 5);
    if (!countSort(unsortedArray, 5)) {
        return false;
    }
    if (!areEqual(unsortedArray, expectedArray, 5)) {
        printf("Smth Went Wrong at count sort =(\n");
        printArray(unsortedArray, 5);
        return false;
    }
    return true;
}

bool testBubbleSort(void) {
    int unsortedArray[5] = { 3, -2, 5, 0, -1 };
    int expectedArray[5] = { -2, -1, 0, 3, 5 };
    bubbleSort(unsortedArray, 5);
    if (!areEqual(unsortedArray, expectedArray, 5)) {
        printf("Smth Went Wrong at bubble sort\n");
        printArray(unsortedArray, 5);
        return false;
    }
    return true;
}
    

int main() {
    if (!(testCountSort() && testBubbleSort())) {
        printf("Tests failed!\n");
    }

    int unsortedArrayForCountSort[4] = {2, 3, -1, 6};
    int unsortedArrayForBubbleSort[4] = {2, 3, -1, 6};

    countSort(unsortedArrayForCountSort, 4);
    printf("time of the CountSort = % ld\n", clock());
    bubbleSort(unsortedArrayForBubbleSort, 4);
    printf("time of the BubbleSort = % ld\n", clock());
}
