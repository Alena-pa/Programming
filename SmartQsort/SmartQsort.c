#include <stdio.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    int justVar = *right;
    if (left != right) {
        *right = *left;
        *left = justVar;
    }
}

void insertionSort(int* arrayOfIntegers, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int currentElement = arrayOfIntegers[i];
        int j = i - 1;

        while (j >= start && arrayOfIntegers[j] > currentElement) {
            arrayOfIntegers[j + 1] = arrayOfIntegers[j];
            j--;
        }
        arrayOfIntegers[j + 1] = currentElement;
    }
}

int partition(int arrayOfIntegers[], int firstIndex, int lastIndex) {
    int pivot = arrayOfIntegers[lastIndex];
    int i = (firstIndex - 1);
    for (int j = firstIndex; j <= lastIndex - 1; j++) {
        if (arrayOfIntegers[j] <= pivot) {
            i++;
            swap(&arrayOfIntegers[i], &arrayOfIntegers[j]);
        }
    }
    swap(&arrayOfIntegers[i + 1], &arrayOfIntegers[lastIndex]);
    return (i + 1);
}

void quickSort(int arrayOfIntegers[], int firstIndex, int lastIndex) {
    if (lastIndex - firstIndex + 1 <= 10) {
        insertionSort(arrayOfIntegers, firstIndex, lastIndex);
    }
    else {
        int indexOfPivot = partition(arrayOfIntegers, firstIndex, lastIndex);
        quickSort(arrayOfIntegers, firstIndex, indexOfPivot - 1);
        quickSort(arrayOfIntegers, indexOfPivot + 1, lastIndex);
    }
}

bool testIfArraysAreTheSame(int* firstArray, int* secondArray, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        if (firstArray[i] != secondArray[i]) {
            return false;
        }
    }
    return true;
}

bool test(void) {
    int arrayOfIntegers[] = { 3, 4, 1, 2 };
    int sortedArrayOfIntegers[] = { 1, 2, 3, 4 };
    quickSort(arrayOfIntegers, 0, 3);
    if (!testIfArraysAreTheSame(arrayOfIntegers, sortedArrayOfIntegers, 4)) {
        return false;
    }
    return true;
}

int main(void) {
    if (!test()) {
        printf("Test falied!");
        return -1;
    }
}
