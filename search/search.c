#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void randomNumbersAtArray(int* array, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
    {
        array[i] = rand();
    }
}

void printArray(int arrayOfIntegers[], int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

bool search(int arrayOfIntegers[], int lenghtOfArray, int searchNumber)
{
    int left = 0;
    int right = lenghtOfArray - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arrayOfIntegers[middle] == searchNumber)
        {
            return true;
        }
        else if (arrayOfIntegers[middle] > searchNumber)
        {
            right -= (lenghtOfArray - 1) / 2;
        }
        else if (arrayOfIntegers[middle] < searchNumber)
        {
            left += (lenghtOfArray - 1) / 2;
        }
    }
    return false;
}

bool test()
{
    int arrayOfIntegers[] = { 0, 1, 2, 3};
    return (search(arrayOfIntegers, 5, 0) && search(arrayOfIntegers, 5, 1) && search(arrayOfIntegers, 5, 2) && search(arrayOfIntegers, 5, 3)
        && !search(arrayOfIntegers, 5, 4) && !search(arrayOfIntegers, 5, 100));
}

void main()
{
    if (!test())
    {
        printf("Test Failed!\n");
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
    int* arrayOfIntegersK = (int*)calloc(k , sizeof(int));
    randomNumbersAtArray(arrayOfIntegersK, k);
    printArray(arrayOfIntegersK, k);
    for (int i = 0; i < k; i++)
    {
        if (search(arrayOfIntegersLenghtIsN, n, arrayOfIntegersK[i]))
        {
            printf("This number: %d is in the array\n", arrayOfIntegersK[i]);
        }
        else
        {
            printf("This number: %d is NOT in the array\n", arrayOfIntegersK[i]);
        }
    }
}