#include <stdio.h>
#include <stdlib.h>

void swap(int* left, int* right)
{
    int justVar = *right;
    if (left != right)
    {
        *right = *left;
        *left = justVar;
    }
}

void bubbleSort(int *arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
    {
        int thisVarShowedIfArraySortedOrNot = 0;
        for (int j = 0; j < lenghtOfArray - 1; j++) 
        {
            if (arrayOfIntegers[j] > arrayOfIntegers[j + 1])
            {
                swap(&arrayOfIntegers[j], &arrayOfIntegers[j + 1]);
                thisVarShowedIfArraySortedOrNot = 1;
            }
        }
        if (thisVarShowedIfArraySortedOrNot == 0)
        {
            break;
        }
    }
}

int maxArray(int * arrayOfIntegers, int lenghtOfArray)
{
    int maxInteger = 0;
    for (int i = 0; i < lenghtOfArray; i++)
    {
        if (arrayOfIntegers[i] > maxInteger)
        {
            maxInteger = arrayOfIntegers[i];
        }
    }
    return maxInteger;
}

void countSort(int *arrayOfIntegers, int lenghtOfArray)
{
    int maxInteger = maxArray(arrayOfIntegers, lenghtOfArray);
    int* countArray = (int*)calloc(maxInteger + 1, sizeof(int));
    for (int i = 0; i < lenghtOfArray; i++) 
    {
        countArray[arrayOfIntegers[i]]++;
    }

    for (int i = 1; i <= maxInteger; i++)
    {
        countArray[i] += countArray[i - 1];
    }
    int* outputArray = (int*)malloc(lenghtOfArray * sizeof(int));
    for (int i = lenghtOfArray - 1; i >= 0; i--)
    {
        outputArray[countArray[arrayOfIntegers[i]] - 1] = arrayOfIntegers[i];
        countArray[arrayOfIntegers[i]]--;
    }

    for (int i = 0; i < lenghtOfArray; i++)
    {
        arrayOfIntegers[i] = outputArray[i];
    }
    free(countArray);
    free(outputArray);
}

void printArray(int* arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

int check(int *firstArray, int *secondArray, int lenghtOfArrays)
{
    int checkingVar = 0;
    for (int i = 0; i < lenghtOfArrays; i++)
    {
        if (firstArray[i] != secondArray[i])
        {
            checkingVar++;
        }
    }
    return checkingVar;
}

void Test1()
{   
    int sortedArrayOfIntegers[5] = { 0, 1, 2, 3, 5 };
    int arrayOfIntegesSortedByCountSort[5] = { 0, 1, 5, 2, 3 };
    countSort(arrayOfIntegesSortedByCountSort, 5);
    int justCheckingVar = check(arrayOfIntegesSortedByCountSort, sortedArrayOfIntegers, 5);
    if (justCheckingVar != 0)
    {
        printf("Smth Went Wrong =(\n");
        printArray(arrayOfIntegesSortedByCountSort, 5);
    }
    int arrayOfIntegesSortedByBubbleSort[5] = { 0, 1, 5, 2, 3 };
    bubbleSort(arrayOfIntegesSortedByBubbleSort, 5);
    int justAnotherCheckingVar = check(arrayOfIntegesSortedByBubbleSort, sortedArrayOfIntegers, 5);
    if (justAnotherCheckingVar != 0)
    {
        printf("Smth Went Wrong\n");
        printArray(arrayOfIntegesSortedByBubbleSort, 5);
    }
}

void Test2()
{
    int sortedArrayOfIntegers[5] = { 0, 1, 3, 2, 5 };
    int arrayOfIntegesSortedByCountSort[5] = { 0, 1, 5, 2, 3 };
    countSort(arrayOfIntegesSortedByCountSort, 5);
    int justCheckingVar = check(arrayOfIntegesSortedByCountSort, sortedArrayOfIntegers, 5);
    if (justCheckingVar != 0)
    {
        printf("All Good =)\n");
        printArray(arrayOfIntegesSortedByCountSort, 5);
    }
    int arrayOfIntegesSortedByBubbleSort[5] = { 0, 1, 5, 2, 3 };
    bubbleSort(arrayOfIntegesSortedByBubbleSort, 5);
    int justAnotherCheckingVar = check(arrayOfIntegesSortedByBubbleSort, sortedArrayOfIntegers, 5);
    if (justAnotherCheckingVar != 0)
    {
        printf("All Good =)\n");
        printArray(arrayOfIntegesSortedByBubbleSort, 5);
    }
}
int main()
{
    Test1();
    Test2();
}
