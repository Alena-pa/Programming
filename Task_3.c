#include <stdio.h>

int answer(int firstNumber, int secondNumber)
{
    if (secondNumber != 0)
    {
        if (firstNumber > 0)
        {
            if (secondNumber > 0)
            {
                int count = divine(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
            }
            else
            {
                secondNumber *= (-1);
                int count = divine(firstNumber, secondNumber);
                count *= (-1);
                int remainNumber = remain(firstNumber, secondNumber);
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
            }
            else
            {
                firstNumber *= (-1);
                secondNumber *= (-1);
                int count = divine(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= (-1);
            }
        }
        printf("Div %d, remain %d", count, remainNumber);
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
