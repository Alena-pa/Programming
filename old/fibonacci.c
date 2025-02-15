#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int recursionFibonacci(int number) {
	if (number <= 0) {
		printf("negative number!");
		return -1;
	}
    if (number == 1 || number == 2) {
        return 1;
    }
    return recursionFibonacci(number - 1) + recursionFibonacci(number - 2);
}

int iterativeFibonacci(int number) {
	if (number <= 0) {
		printf("negative number!");
		return -1;
	}
    if (number <= 1) {
        return number;
    }
    int numberFibPrevios = 0;
    int numberFibCurrent = 1;
    for (int i = 2; i <= number; i++) {
        int numberFibNext = numberFibPrevios + numberFibCurrent;
        numberFibPrevios = numberFibCurrent;
        numberFibCurrent = numberFibNext;
    }
    return numberFibCurrent;
}

void compareTime(void) {
    for (int i = 20; i < 50; i++) {
        clock_t start = clock();
        recursionFibonacci(i);
        clock_t timeOfDoingRecursionFibonacci = clock() - start;
        printf("%d\n", timeOfDoingRecursionFibonacci);
        start = clock();
        printf("%d\n", iterativeFibonacci(i));
        clock_t timeOfDoingIterativeFibonacci = clock() - start;
        printf("%d\n", timeOfDoingIterativeFibonacci);
        if (timeOfDoingRecursionFibonacci - timeOfDoingIterativeFibonacci > 5 * CLOCKS_PER_SEC) {
            printf("starting from this number the iterative method is faster than the recursive one: %d", i);
            return;
        }
    }
}

bool testRecursionFibonacci(void) {
    return (recursionFibonacci(1) == 1 && recursionFibonacci(2) == 1 && recursionFibonacci(10) == 55 && recursionFibonacci(-5) == -1);
}

bool testIterativeFibonacci(void) {
    return (recursionFibonacci(1) == 1 && recursionFibonacci(2) == 1 && recursionFibonacci(10) == 55 && recursionFibonacci(-5) == -1);
}

int main(void) {
	if (!(testRecursionFibonacci() && testIterativeFibonacci())) {
		printf("Tests failed!");
		return -1;
	}
    compareTime();
}
