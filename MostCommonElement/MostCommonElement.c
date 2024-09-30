#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int arrayOfIntegers[5] = { 1, 1, 2, 3, 4 };
    int most = mostCommonElement(arrayOfIntegers, 5);
    printf("%d", most);
}
