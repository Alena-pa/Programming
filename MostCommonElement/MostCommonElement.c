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


int mostCommonElement(int* arrayOfIntegers, int lenghtOfArray)
{
    int maxInteger = maxArray(arrayOfIntegers, lenghtOfArray);
    int* countArray = (int*)calloc(maxInteger + 1, sizeof(int));
    for (int i = 0; i < lenghtOfArray; i++)
    {
        countArray[arrayOfIntegers[i]]++;
    }
    int maxCommonNum = 0;
    int mostCommon = 0;
    for (int i = 0; i < maxInteger + 1; i++)
    {
        if (countArray[i] > mostCommon)
        {
            mostCommon = countArray[i];
            maxCommonNum = i;
        }
    }
    return maxCommonNum;
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
}
