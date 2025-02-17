#include <stdio.h>
#include <stdbool.h>

void swap(int *left, int *right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void reverseSubArrayOfIntegers(int* arrayOfIntegers, int begin, int end) {
    for ( ;begin < end; begin++, end--) {
        swap(&arrayOfIntegers[begin], &arrayOfIntegers[end]);
    }
}

void reverseSegments(int *arrayOfIntegers, int m, int n) {
    reverseSubArrayOfIntegers(arrayOfIntegers, 0, m - 1);
    reverseSubArrayOfIntegers(arrayOfIntegers, m, m + n - 1);
    reverseSubArrayOfIntegers(arrayOfIntegers, 0, m + n - 1);
}

bool areArrayEqual(int* firstArray, int* secondArray, int length) {
    for (int i = 0; i < length; i++) {
        if (firstArray[i] != secondArray[i]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int first = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int expectedFirst = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };

    int second = { 10, 20, 30, 40, 50, 60 };
    int expectedSecond = { 40, 50, 60, 10, 20, 30 };

    return areArrayEqual(first, expectedFirst, 9) && areArrayEqual(second, expectedSecond, 6);
}

int main(void) {
    if (!test()) {
        printf("Tests failed!")
        return;
    }
}
