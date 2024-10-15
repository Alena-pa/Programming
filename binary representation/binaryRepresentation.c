#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

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


int answer(int firstNumber, int secondNumber)
{
    setlocale(LC_ALL, "Rus");
    int firstBinaryNumber[32] = { 0 };
    int secondBinaryNumber[33] = { 0 };

    numberToBinaryFromDecimal(firstBinaryNumber, firstNumber);
    numberToBinaryFromDecimal(secondBinaryNumber, secondNumber);
    printf("Первое двочиное число: ");
    printArray(firstBinaryNumber, 32);
    printf("Второе двочиное число: ");
    printArray(secondBinaryNumber, 32);

    int sumOfBinaryNUmbers[32] = { 0 };
    addingbinarynumbers(firstBinaryNumber, secondBinaryNumber, sumOfBinaryNUmbers);
    printf("Сумма двоичных чисел: ");
    printArray(sumOfBinaryNUmbers, 32);

    int sumOfBinaryNumbersAsDecimal = numberFromBinaryToDecimal(sumOfBinaryNUmbers);
    printf("Сумма двоичных чисел в десятичной системе: %d\n", sumOfBinaryNumbersAsDecimal);
    return sumOfBinaryNumbersAsDecimal;
}

bool test()
{
    return (answer(1, 5) == 6 && answer(0, 0) == 0 && answer(1, 0) == 1 && answer(5, 5) == 10);
}

int main()
{

    if (!test())
    {
        printf("Тест Завален!!!");
        return -1;
    }

    answer(5, 1);
    answer(4, 8);
}