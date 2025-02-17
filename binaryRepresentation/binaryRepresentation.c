#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "binaryRepresentation.h"
#define NUM_SIZE (sizeof(int) * 8)

void printArray(int arrayOfIntegers[], int lenghtOfArray) {
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%d", arrayOfIntegers[i]);
    printf("\n");
}

void numberToBinaryFromDecimal(int* array, int number) {
    int mask = 1;
    for (int i = NUM_SIZE - 1; i >= 0; i--) {
        if ((number & mask) == 0) {
            array[i] = 0;
        }
        else {
            array[i] = 1;
        }
        mask = mask << 1;
    }
}

int numberFromBinaryToDecimal(int* binaryNumber) {
    int decimalNumber = 0;
    int power = 0;
    int mask = 1;
    for (int i = NUM_SIZE - 1; i >= 0; i--) {
        if (binaryNumber[i] == 1) {
            decimalNumber += mask;
        }
        mask = mask << 1;
    }
    return decimalNumber;
}

void addBinaryNumbers(int* firstNumber, int* secondNumber, int* sumOfBinaryNumbers) {
    int carry = 0;
    for (int i = NUM_SIZE - 1; i >= 0; i--) {
        if (firstNumber[i] + secondNumber[i] + carry == 3) {
            sumOfBinaryNumbers[i] = 1;
            carry = 1;
        }
        else if (firstNumber[i] + secondNumber[i] + carry == 2) {
            sumOfBinaryNumbers[i] = 0;
            carry = 1;
        }
        else if (firstNumber[i] + secondNumber[i] + carry == 1) {
            sumOfBinaryNumbers[i] = 1;
            carry = 0;
        }
        else if (firstNumber[i] + secondNumber[i] + carry == 0) {
            sumOfBinaryNumbers[i] = 0;
            carry = 0;
        }
    }

}

int answer(int firstNumber, int secondNumber) {
    setlocale(LC_ALL, "Rus");
    int firstBinaryNumber[NUM_SIZE] = { 0 };
    int secondBinaryNumber[NUM_SIZE + 1] = { 0 };

    numberToBinaryFromDecimal(firstBinaryNumber, firstNumber);
    numberToBinaryFromDecimal(secondBinaryNumber, secondNumber);
    printf("Первое двочиное число: ");
    printArray(firstBinaryNumber, NUM_SIZE);
    printf("Второе двочиное число: ");
    printArray(secondBinaryNumber, NUM_SIZE);

    int sumOfBinaryNUmbers[NUM_SIZE] = { 0 };
    addBinaryNumbers(firstBinaryNumber, secondBinaryNumber, sumOfBinaryNUmbers);
    printf("Сумма двоичных чисел: ");
    printArray(sumOfBinaryNUmbers, NUM_SIZE);

    int sumOfBinaryNumbersAsDecimal = numberFromBinaryToDecimal(sumOfBinaryNUmbers);
    printf("Сумма двоичных чисел в десятичной системе: %d\n", sumOfBinaryNumbersAsDecimal);
    return sumOfBinaryNumbersAsDecimal;
}
