#include "MostCommonElement.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left != right) {
        int temp = *right;
        *right = *left;
        *left = temp;
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
    int i = firstIndex - 1;
    for (int j = firstIndex; j <= lastIndex - 1; j++) {
        if (arrayOfIntegers[j] <= pivot) {
            i++;
            swap(&arrayOfIntegers[i], &arrayOfIntegers[j]);
        }
    }
    swap(&arrayOfIntegers[i + 1], &arrayOfIntegers[lastIndex]);
    return i + 1;
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

int mostCommonElement(int* arrayOfIntegers, int lengthOfArray) {
    quickSort(arrayOfIntegers, 0, lengthOfArray - 1);
    int lastMostCommonElement = arrayOfIntegers[0];
    int countOfCurrentMostCommonElement = 1;
    int previousElement = arrayOfIntegers[0];
    int countOfCurrentElement = 1;
    for (int i = 1; i < lengthOfArray; i++) {
        if (arrayOfIntegers[i] == previousElement) {
            countOfCurrentElement++;
        }
        else {
            if (countOfCurrentElement > countOfCurrentMostCommonElement) {
                countOfCurrentMostCommonElement = countOfCurrentElement;
                lastMostCommonElement = previousElement;
            }
            previousElement = arrayOfIntegers[i];
            countOfCurrentElement = 1;
        }
    }

    if (countOfCurrentMostCommonElement < countOfCurrentElement) {
        countOfCurrentMostCommonElement = countOfCurrentElement;
        lastMostCommonElement = previousElement;
    }

    return lastMostCommonElement;
}