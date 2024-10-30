#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxArray(int* arrayOfIntegers, int lenghtOfArray)
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

bool Test()
{
    int arrayOfIntegers[5] = { 1, 2, 2, 3, 4 };
    int anotherArrayOfIntegers[5] = { 0, 0, 2, 3, 3 };
    return (mostCommonElement(arrayOfIntegers, 5) == 2 && (mostCommonElement(anotherArrayOfIntegers, 5) == 0 || mostCommonElement(anotherArrayOfIntegers, 5) == 3));
}

int main()
{
    if (!Test)
    {
        printf("Snth Went Wrong!!!!!!!!!!!");
    }
    int arrayOFIntegers[] = { 1, 8, 4, 2, 5, 8, 8, 4 };
    int value = mostCommonElement(arrayOFIntegers, 9);
    printf("%d", value);
}
