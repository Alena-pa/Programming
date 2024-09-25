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

int incompleteQuotientCount(int firstNumber, int secondNumber)
{
    if (secondNumber == 0)
    {
        return firstNumber;
    }
    else
    {
        if (firstNumber > 0)
        {
            if (secondNumber > 0)
            {
                int count = divide(firstNumber, secondNumber); 
                return count;
            }
            else
            {
                secondNumber *= -1;
                int count = divide(firstNumber, secondNumber);
                count *= -1;   
                return count;
            }
        }
        else
        {
            if (secondNumber > 0)
            {
                firstNumber *= -1;
                int count = divide(firstNumber, secondNumber);
                count *= -1;
                return count;
            }
            else
            {
                firstNumber *= -1;
                secondNumber *= -1;
                int count = divide(firstNumber, secondNumber);      
                return count;
            }
        }
    }
}

int incompleteQuotientCountRemainNumber(int firstNumber, int secondNumber)
{
    if (secondNumber == 0)
    {
        return secondNumber;
    }
    else
    {
        if (firstNumber > 0)
        {
            if (secondNumber > 0)
            {
                int remainNumber = remain(firstNumber, secondNumber);
                return remainNumber;
            }
            else
            {
                secondNumber *= -1;              
                int remainNumber = remain(firstNumber, secondNumber);
                return remainNumber;
            }
        }
        else
        {
            if (secondNumber > 0)
            {
                firstNumber *= -1;
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= -1;
                return remainNumber;
            }
            else
            {
                firstNumber *= -1;
                secondNumber *= -1;
                int remainNumber = remain(firstNumber, secondNumber);
                remainNumber *= -1;
                return remainNumber;
            }
        }
    }
}

void incompleteQotient(int *firstNumber, int *secondNumber)
{

    int lastCount = incompleteQuotientCount(firstNumber, secondNumber);
    int lastRemainNumber = incompleteQuotientCountRemainNumber(firstNumber, secondNumber);
    if (lastCount != firstNumber & lastRemainNumber != secondNumber)
    {
        printf("Div = %d\nremain = %d\n", lastCount, lastRemainNumber);
    }
    else
    {
        printf("Incorrect condition!");
    }
}

int main()
{
    int firstNumber = 100;
    int secondNumber = -3;
    incompleteQotient(firstNumber, secondNumber);
}
