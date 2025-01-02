#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void randomNumbersAtArray(int* array, int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        array[i] = rand();
    }
}

void swap(int* left, int* right) {
    int justVar = *right;
    if (left != right) {
        *right = *left;
        *left = justVar;
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
    if (firstIndex < lastIndex) {
        int indexOfPivot = partition(arrayOfIntegers, firstIndex, lastIndex);
        quickSort(arrayOfIntegers, firstIndex, indexOfPivot - 1);
        quickSort(arrayOfIntegers, indexOfPivot + 1, lastIndex);
    }
}

void printArray(int arrayOfIntegers[], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

bool search(int arrayOfIntegers[], int lengthOfArray, int searchNumber) {
    int left = 0;
    int right = lengthOfArray - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arrayOfIntegers[middle] == searchNumber) {
            return true;
        }
        else if (arrayOfIntegers[middle] > searchNumber) {
            right = middle - 1;
        }
        else if (arrayOfIntegers[middle] < searchNumber) {
            left = middle + 1;
        }
    }
    return false;
}

bool test(void) {
    int arrayOfIntegers[] = { 0, 1, 2, 3};
    return (search(arrayOfIntegers, 5, 0) && search(arrayOfIntegers, 5, 1) && search(arrayOfIntegers, 5, 2) && search(arrayOfIntegers, 5, 3)
        && !search(arrayOfIntegers, 5, 4) && !search(arrayOfIntegers, 5, 100));
}

int main(void) {
    if (!test()) {
        printf("Test Failed!\n");
        return -1;
    }
    
    int n = 0;
    int k = 0;
    printf("Enter number 'n'\n");
    scanf("%d", &n);
    printf("Enter number 'k'\n");
    scanf("%d", &k);
    
    int* arrayOfIntegersLenghtIsN = (int*)calloc(n, sizeof(int));
    randomNumbersAtArray(arrayOfIntegersLenghtIsN, n);
    printArray(arrayOfIntegersLenghtIsN, n);
    quickSort(arrayOfIntegersLenghtIsN,0 , n - 1);
    printArray(arrayOfIntegersLenghtIsN, n);
    
    int* arrayOfIntegersK = (int*)calloc(k , sizeof(int));
    randomNumbersAtArray(arrayOfIntegersK, k);
    printArray(arrayOfIntegersK, k);
    
    for (int i = 0; i < k; i++) {
        if (search(arrayOfIntegersLenghtIsN, n, arrayOfIntegersK[i])) {
            printf("This number: %d is in the array\n", arrayOfIntegersK[i]);
        }
        else {
            printf("This number: %d is NOT in the array\n", arrayOfIntegersK[i]);
        }
    }
    free(arrayOfIntegersLenghtIsN);
    free(arrayOfIntegersK);
}
