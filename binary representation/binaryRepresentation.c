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

int* numberToBinaryFromDecimal(int number)
{
    char* binaryNum = (char*)malloc(32);
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

int* addingBinaryNumbers(char *firstNumber, char *secondNumber)
{
    int carry = 0;
    char sumOfBinaryNumber = (char*)malloc(64);
    int lenght = max(strlen(firstNumber), strlen(secondNumber));
    for (int i = lenght - 1; i >= 0; i--)
    {
        int firstDigit = firstNumber[i] - '0';
        int secondDigit = secondNumber[i] - '0';
        sumOfBinaryNumber[i] = (firstDigit + secondDigit + carry) % 2;
        carry = (firstDigit + secondDigit + carry) / 2;
    }
    if (carry == 1)
    {
        sumOfBinaryNumber[0] = 1;
    }
    return sumOfBinaryNumber;
}

void printArray(char arrayOfIntegers[], int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%c", arrayOfIntegers[i]);
    printf("\n");
}

void answer(int firstNumber, int secondNumber)
{
    printf("first number: %d\nsecond number: %d", firstNumber, secondNumber);
    char FirstBinaryNumber = numberToBinaryFromDecimal(firstNumber);
    char SecondBinaryNumber = numberToBinaryFromDecimal(secondNumber);
    printf("first binary number: ");
    printArray(FirstBinaryNumber, strlen(FirstBinaryNumber));
    printf("second binary number: ");
    printArray(SecondBinaryNumber, strlen(SecondBinaryNumber));
    char sumOfBinaryNumbers = addingBinaryNumbers(FirstBinaryNumber, SecondBinaryNumber);
    printf("Sum of Binary numbers: ");
    printArray(sumOfBinaryNumbers, strlen(sumOfBinaryNumbers));
    int firstDecimalNumber = numberFromBinaryToDecimal(FirstBinaryNumber);
    int secondDecimalNumber = numberFromBinaryToDecimal(SecondBinaryNumber);
    printf("first Decimal number: %d\nsecond Decimal number: %d\n", firstDecimalNumber, secondDecimalNumber);
    int sumOfBinaryNumbersInDecimal = numberFromBinaryToDecimal(sumOfBinaryNumbers);
    prinf("Sum of Binary Numbers in decimal: %d\n Sum of decimal numbers: %d\n", sumOfBinaryNumbersInDecimal, firstDecimalNumber + secondDecimalNumber);
}

int main()
{
    answer(5, 4);
} 