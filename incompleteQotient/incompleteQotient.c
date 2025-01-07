#include <stdio.h>
#include <math.h>

void incompleteQotient(int firstNumber, int secondNumber) {
    if (secondNumber == 0) {
        printf("Incorrect condition! Division by zero!");
        return;
    }
    int signOfNumbers = 1;
    if ((firstNumber > 0 && secondNumber < 0) || (firstNumber < 0 && secondNumber > 0)) {
        signOfNumbers = -1;
    }

    int qoient = 0;
    int tmp = 0;
    while ((firstNumber - tmp < 0) || (firstNumber - tmp >= abs(secondNumber))) {
        tmp = tmp + signOfNumbers * secondNumber;
        qoient += signOfNumbers;
    }

    int remain = firstNumber - tmp;
    printf("Qotient = %d , remain = %d\n", qoient, remain);
}

void test() {
    incompleteQotient(12, 5);
    incompleteQotient(-12, 5);
    incompleteQotient(12, -5);
    incompleteQotient(-12, -5);
}

int main() {
    test();
}