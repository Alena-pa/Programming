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

void randomise(int* arrayOfIntegers, int lenghtOfArray)
{
	for (int i = 0; i < lenghtOfArray; i++)
	{
		arrayOfIntegers[i] = rand() % 10;
	}
}

void sortingArrayOfIntegers(int *arrayOfIntegers, int lenghtOfArray)
{
    int lastChangedIndex = 0;
    for (int i = 1; i < lenghtOfArray; i++)
    {
        if (arrayOfIntegers[i] > arrayOfIntegers[i - 1])
        {            
            swap(&arrayOfIntegers[i], &arrayOfIntegers[lastChangedIndex]);
            int lastChangedIndex = i;
        }
    }
}

void printArray(int* arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d ", arrayOfIntegers[i]);
    printf("\n");
}

int main()
{
	int arrayOfIntegers[10] = { 0 };
    randomise(arrayOfIntegers, 10);
    printArray(arrayOfIntegers, 10);
    sortingArrayOfIntegers(arrayOfIntegers, 10);
    printArray(arrayOfIntegers, 10);
}
