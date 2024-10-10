#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void reverse(char* string)
{
    int firstIndex = 0;
    int lastIndex = strlen(string) - 1;
    char letter;
    while (firstIndex < lastIndex)
    {
        letter = string[firstIndex];
        string[firstIndex] = string[lastIndex];
        string[lastIndex] = letter;
        firstIndex++;
        lastIndex--;
    }
}

int numberToBinaryFromDecimal(int number)
{
    int binaryNum[32];
    for (int i = 0; number > 0; i++)
    {
        binaryNum[i] = number % 2;
        number /= 2;
    }
    reverse(binaryNum);
    return binaryNum;
}

int numberFromBinaryToDecimal(char *binaryNumber)
{
    int decimalNumber = 0;
    int power = 0;
    for (int i = strlen(binaryNumber) - 1; i >= 0; i--)
    {
        if (binaryNumber[i] == '1')
        {
            decimalNumber += pow(2, power);
        }
        power++;
    }
    return decimalNumber;
}

int addingBinaryNumbers(char *firstNumber, char *secondNumber)
{
    int carry = 0;
    int sumOfBinaryNumber[64];
    for (int i = strlen(firstNumber) - 1; i >= 0; i--)
    {
        if (atoi(firstNumber[i]) + atoi(secondNumber[i] > 1))
        {
            
        }
    }
    
}

void answer(int firstNumber, int *secondNumber)
{
    prinf("first number: %d\nsecond number: %d", firstNumber, secondNumber);
    char FirstBinaryNumber = numberToBinaryFromDecimal(firstNumber);
    char SecondBinaryNumber = numberToBinaryFromDecimal(secondNumber);
    printf("first binary Number: %s\nsecond binary Number: %s\n", FirstBinaryNumber, SecondBinaryNumber);
    char sumOfBinaryNumbers = addingBinaryNumbers(FirstBinaryNumber, )
}

int main()
{
    
}