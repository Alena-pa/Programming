#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(const char* binaryString, char* buff) {
    int binaryNumber = atoi(binaryString);
    int decimalNumber = 0;
    int base = 1;
    int temp = binaryNumber;

    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;
        decimalNumber += lastDigit * base;
        base = base * 2;
    }

    itoa(decimalNumber, buff, 10);
}

bool test() {
    char decimalString1[33];
    char decimalString2[33];
    char decimalString3[33];

    convert("0", decimalString1);
    convert("111", decimalString2);
    convert("1011", decimalString3);
    return (strcmp(decimalString1, "0") == 0 && strcmp(decimalString2, "7") == 0 && strcmp(decimalString3, "11") == 0);
}

int main(void) {
    if (!test()) {
        printf("tests failed!");
        return 1;
    }
    char decimalString[33];
    convert("11100", decimalString);
    printf("%s", decimalString);
}