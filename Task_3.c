#include <stdio.h>

int divide(int firstNumber, int secondNumber)
{
    int count = 0;
    while (firstNumber >= secondNumber)
    {
        firstNumber = firstNumber - secondNumber;
        count++;
    }
    return count;
}

int answer(int firstNumber, int secondNumber)
{
    if (secondNumber != 0)
    {
        if (firstNumber > 0)
        {
            if (secondNumber > 0)
            {
                int count = divide(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
                printf("Div %d, remain %d", count, remainNumber);
            }
            else
            {
                secondNumber *= -1;
                int count = divide(firstNumber, secondNumber);
                count *= -1;
                int remainNumber = remain(firstNumber, secondNumber);
                printf("Div %d, remain %d", count, remainNumber);
            }
        }
        else
        {
            if (secondNumber > 0)
            {
                firstNumber *= -1;
                int count = divide(firstNumber, secondNumber);
                count *= -1;
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= -1;
                printf("Div %d, remain %d", count, remainNumber);
            }
            else
            {
                firstNumber *= -1;
                secondNumber *= -1;
                int count = divide(firstNumber, secondNumber);
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= -1;
                printf("Div %d, remain %d", count, remainNumber);
            }
        }
    }
    else
    {
        // prinf if secondNumber == 0
        printf("Incorrect condition!");
    }
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
