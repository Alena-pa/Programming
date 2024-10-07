#include <stdio.h>
#include <stdbool.h>

void swap(int* left, int* right)
{
    int justVar = *right;
    if (left != right)
    {
        *right = *left;
        *left = justVar;
    }
}

void insertionSort(int* arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 1; i < lenghtOfArray; i++)
    {
        int lastNumber = arrayOfIntegers[i];
        int j = i - 1;
        while (j >= 0 && arrayOfIntegers[j] > lastNumber)
        {
            arrayOfIntegers[j + 1] = arrayOfIntegers[j];
            j -= 1;
        }
        arrayOfIntegers[j + 1] = lastNumber;
    }
}

int partition(int arrayOfIntegers[], int firstIndex, int lastIndex)
{
    int pivot = arrayOfIntegers[lastIndex];
    int i = (firstIndex - 1);
    for (int j = firstIndex; j <= lastIndex - 1; j++)
    {
        if (arrayOfIntegers[j] <= pivot)
        {
            i++;
            swap(&arrayOfIntegers[i], &arrayOfIntegers[j]);
        }
    }
    swap(&arrayOfIntegers[i + 1], &arrayOfIntegers[lastIndex]);
    return (i + 1);
}

void quickSort(int arrayOfIntegers[], int firstIndex, int lastIndex)
{
    if (lastIndex - firstIndex + 1 <= 10)
    {
        insertionSort(arrayOfIntegers, lastIndex - firstIndex + 1);
    }
    else
    {
        int indexOfPivot = partition(arrayOfIntegers, firstIndex, lastIndex);
        quickSort(arrayOfIntegers, firstIndex, indexOfPivot - 1);
        quickSort(arrayOfIntegers, indexOfPivot + 1, lastIndex);
    }
}

bool testIfArraysAreTheSame(int* firstArray, int* secondArray, int lenghtOfArrays)
{
    for (int i = 0; i < lenghtOfArrays; i++)
    {
        if (firstArray[i] != secondArray[i])
        {
            return false;
        }
    }
    return true;
}

bool test()
{
    int arrayOfIntegers[] = { 3, 4, 1, 2 };
    int sortedArrayOfIntegers[] = { 1, 2, 3, 4 };
    quickSort(arrayOfIntegers, 0, 3);
    if (!testIfArraysAreTheSame(arrayOfIntegers, sortedArrayOfIntegers, 4))
    {
        return false;
    }
    return true;
}
void main()
{
    if (!test)
    {
        printf("Test falied!");
    }
}