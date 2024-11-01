#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSorted(int* array, int lenghtOfArray) {
	for (int i = 1; i < lenghtOfArray; i++) {
		if (array[i - 1] > array[i]) {
			return false;
		}
	}
	return true;
}

void shuffle(int* array, int lenghtOfArray) {
	for (int i = 0; i < lenghtOfArray; i++) {
		int tempInt = array[i];
		int tempIndex = rand() % lenghtOfArray;
		array[i] = array[tempIndex];
		array[tempIndex] = tempInt;
	}
}

void bogoSort(int* array, int lenghtOfArray) {
	while (!isSorted(array, lenghtOfArray)) {
		shuffle(array, lenghtOfArray);
	}
}

bool compareArrays(int *firstArray, int *secondArray, int lenghtOfArrays) {
	for (int i = 0; i < lenghtOfArrays; i++) {
		if (firstArray[i] != secondArray[i]) {
			return false;
		}
	}
	return true;
}

bool test() {
	int firstArray[2] = { 1, 2 };
	int secondArray[2] = { 2, 1 };
	if (!compareArrays(firstArray, secondArray, 2)) {
		return false;
	}
	return true;
}


int main(void) {
	if (!test) {
		printf("test Failed!");
	}
}