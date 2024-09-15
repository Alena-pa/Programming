#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int answer(int firstNumber, int secondNumber)
{
    if (abs(firstNumber) >= abs(secondNumber) && secondNumber != 0)
    {
        if (firstNumber > 0)
        {
            if (secondNumber > 0)
            {
                int count = divine(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
                printf("Div %d, remain %d", count, remainNumber);
            }
            else
            {
                secondNumber *= (-1);
                int count = divine(firstNumber, secondNumber);
                count *= (-1);
                int remainNumber = remain(firstNumber, secondNumber);
                printf("Div %d, remain %d", count, remainNumber);
            }
        }
        else
        {
            if (secondNumber > 0)
            {
                firstNumber *= (-1);
                int count = divine(firstNumber, secondNumber);
                count *= (-1);
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= (-1);
                printf("Div %d, remain %d", count, remainNumber);
            }
            else
            {
                firstNumber *= (-1);
                secondNumber *= (-1);
                int count = divine(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= (-1);
                printf("Div %d, remain %d", count, remainNumber);
            }
        }
    }
    else
    {
        printf("Incorrect condition!");
    }
}

int divine(int firstNumber, int secondNumber)
{
    int count = 0;
    while (firstNumber >= secondNumber)
    {
        firstNumber = firstNumber - secondNumber;
        count++;
    }
    return count;
}

int remain(int firstNumber, int secondNumber)
{
    int count = 0;
    while (firstNumber >= secondNumber)
    {
        firstNumber = firstNumber - secondNumber;
        count++;
    }
    return firstNumber;
}

int main()
{
    int firstNumber = 100;
    int secondNumber = -3;
    answer(firstNumber, secondNumber);
}
