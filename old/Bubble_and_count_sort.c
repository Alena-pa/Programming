#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int* left, int* right) {
    if (left == right) {
        return;
    }

    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}

void bubbleSort(int *arrayOfIntegers, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        bool isSorted = false;
        for (int j = 0; j < lengthOfArray - 1; j++) {
            if (arrayOfIntegers[j] > arrayOfIntegers[j + 1]) {
                swap(&arrayOfIntegers[j], &arrayOfIntegers[j + 1]);
                isSorted = true;
            }
        }
        if (!isSorted) {
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

int minArray(int* arrayOfIntegers, int lengthOfArray) {
    int minInteger = 100000;
    for (int i = 0; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] < minInteger) {
            minInteger = arrayofIntegers[i];
        }
    }
    return minInteger;
}

void countSort(int *arrayOfIntegers, int lenghtOfArray) {
    int maxInteger = maxArray(arrayOfIntegers, lenghtOfArray);

    int* countArray = (int*)calloc(maxInteger + 1, sizeof(int));
    if (countArray == NULL) {
        printf("Not enough memory!");
        return;
    }
 
    for (int i = 0; i < lenghtOfArray; i++)  {
        countArray[arrayOfIntegers[i]]++;
    }

    for (int i = 1; i <= maxInteger; i++) {
        countArray[i] += countArray[i - 1];
    }

}

void printArray(int* arrayOfIntegers, int lenghtOfArray) {
    for (int i = 0; i < lenghtOfArray; i++) {
        printf("%d ", arrayOfIntegers[i]);
    }
    printf("\n");
}

int check(int *firstArray, int *secondArray, int lenghtOfArrays) {
    int checkingVar = 0;
    for (int i = 0; i < lenghtOfArrays; i++) {
        if (firstArray[i] != secondArray[i]) {
            checkingVar++;
        }
    }
    return checkingVar;
}

void Test1() {   
    int sortedArrayOfIntegers[5] = { 0, 1, 2, 3, 5 };
    int arrayOfIntegesSortedByCountSort[5] = { 0, 1, 5, 2, 3 };
    countSort(arrayOfIntegesSortedByCountSort, 5);
    int justCheckingVar = check(arrayOfIntegesSortedByCountSort, sortedArrayOfIntegers, 5);
    if (justCheckingVar != 0) {
        printf("Smth Went Wrong =(\n");
        printArray(arrayOfIntegesSortedByCountSort, 5);
    }
    printf("time of the CountSort = % ld\n", clock());
    int arrayOfIntegesSortedByBubbleSort[5] = { 0, 1, 5, 2, 3 };
    bubbleSort(arrayOfIntegesSortedByBubbleSort, 5);
    int justAnotherCheckingVar = check(arrayOfIntegesSortedByBubbleSort, sortedArrayOfIntegers, 5);
    if (justAnotherCheckingVar != 0) {
        printf("Smth Went Wrong\n");
        printArray(arrayOfIntegesSortedByBubbleSort, 5);
    }
    printf("time of the BubbleSort = % ld\n", clock());
}

void Test2() {
    int sortedArrayOfIntegers[5] = { 0, 1, 3, 2, 5 };
    int arrayOfIntegesSortedByCountSort[5] = { 0, 1, 5, 2, 3 };
    countSort(arrayOfIntegesSortedByCountSort, 5);
    int justCheckingVar = check(arrayOfIntegesSortedByCountSort, sortedArrayOfIntegers, 5);
    if (justCheckingVar != 0) {
        printf("All Good =)\n");
        printArray(arrayOfIntegesSortedByCountSort, 5);
    }
    printf("time of the CountSort = % ld\n", clock());
    int arrayOfIntegesSortedByBubbleSort[5] = { 0, 1, 5, 2, 3 };
    bubbleSort(arrayOfIntegesSortedByBubbleSort, 5);
    int justAnotherCheckingVar = check(arrayOfIntegesSortedByBubbleSort, sortedArrayOfIntegers, 5);
    if (justAnotherCheckingVar != 0) {
        printf("All Good =)\n");
        printArray(arrayOfIntegesSortedByBubbleSort, 5);
    }
    printf("time of the BubbleSort = % ld\n", clock());
}
int main() {
    Test1();
    Test2();
}
