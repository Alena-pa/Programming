#include <stdio.h>

void swap(int *left, int *right)
{
    if (left != right)
    {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void reverseSubArrayOfIntegers(int* arrayOfIntegers, int begin, int end)
{
    for (;begin < end; begin++, end--){
        swap(&arrayOfIntegers[begin], &arrayOfIntegers[end]);
    }
}

void printArray(int *arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

void reverseSegments(int *arrayOfIntegers, int lenghtOfArray){
    int middle = lenghtOfArray / 2;
    reverseSubArrayOfIntegers(arrayOfIntegers, 0, middle - 1);
    reverseSubArrayOfIntegers(arrayOfIntegers, middle, lenghtOfArray - 1);
    reverseSubArrayOfIntegers(arrayOfIntegers, 0, lenghtOfArray - 1);
}

int main(void)
{
    int arrayOfIntegers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArray(arrayOfIntegers, 9);
    reverseSegments(arrayOfIntegers, 9);
    printArray(arrayOfIntegers, 9);
}
