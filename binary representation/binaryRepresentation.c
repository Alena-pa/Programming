#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arrayOfIntegers[], int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d", arrayOfIntegers[i]);
    printf("\n");
}

void numberToBinaryFromDecimal(int *array, int number)
{
    int mask = 1;
    for (int i = 32 - 1; i >= 0; i--) {
        if ((number & mask) == 0)
        {
            array[i] = 0;
        }
        else
        {
            array[i] = 1;
        }
        mask = mask << 1;
    }
}

int numberFromBinaryToDecimal(int *binaryNumber)
{
    int decimalNumber = 0;
    int power = 0;
    int mask = 1;
    for (int i = 32 - 1; i >= 0; i--)
    {
        if (binaryNumber[i] == 1)
        {
            decimalNumber += mask;
        }
        mask = mask << 1;
    }
    return decimalNumber;
}

void addingbinarynumbers(int* firstnumber, int* secondnumber, int* sumOfBinaryNumbers)
{
    int carry = 0;
    for (int i = 32 - 1; i >= 0; i--)
    {
        if (firstnumber[i] + secondnumber[i] + carry == 3)
        {
            sumOfBinaryNumbers[i] = 1;
            carry = 1;
        }
        else if (firstnumber[i] + secondnumber[i] + carry == 2)
        {
            sumOfBinaryNumbers[i] = 0;
            carry = 1;
        }
        else if (firstnumber[i] + secondnumber[i] + carry == 1)
        {
            sumOfBinaryNumbers[i] = 1;
            carry = 0;
        }
        else if (firstnumber[i] + secondnumber[i] + carry == 0)
        {
            sumOfBinaryNumbers[i] = 0;
            carry = 0;
        }
    }
    if (carry == 1)
    {
        
    }
}

bool test()
{
    int firstNumber = 1;
    int secondNumber = 2;
    int firstBinaryNumber[32] = { 0 };
    int secondBinaryNumber[32] = { 0 };

}

void answer(int firstNumber, int secondNumber)
{
    int firstBinaryNumber[32] = { 0 };
    int secondBinaryNumber[33] = { 0 };

    numberToBinaryFromDecimal(firstBinaryNumber, firstNumber);
    numberToBinaryFromDecimal(secondBinaryNumber, secondNumber);
    printf("First Binary Number: ");
    printArray(firstBinaryNumber, 32);
    printf("Second Binary Number: ");
    printArray(secondBinaryNumber, 32);

    int sumOfBinaryNUmbers[32] = { 0 };
    addingbinarynumbers(firstBinaryNumber, secondBinaryNumber, sumOfBinaryNUmbers);
    printf("Sum of binary numbers: ");
    printArray(sumOfBinaryNUmbers, 32);

    int sumOfBinaryNumbersAsDecimal = numberFromBinaryToDecimal(sumOfBinaryNUmbers);
    printf("sum of Numbers %d\n", sumOfBinaryNumbersAsDecimal);
}

int main()
{
    answer(5, 1);
    answer(4, 8);
}