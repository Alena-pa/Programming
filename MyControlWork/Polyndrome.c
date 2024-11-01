#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void reverseString(char* string, int lenghtOfstring) {
	for (int i = 0, j = lenghtOfstring - 1; i < lenghtOfstring; i++, j--) {
		char tempString = string[j];
		string[i] = string[j];
		string[j] = tempString;
	}
}

void fromIntToString(int number, char* string) {
	int i = 0;
	if (number < 0) {
		number = number * (-1);
	}
	while (number > 0) {
		string[i++] = number % 10 + '0';
		number /= 10;
	}
	string[i] = '\0';
}

int lenghtOfString(char* string) {
	int i = 0;
	while (string[i] != '\0') {
		i++;
	}
	return i;
}

bool isNumberPolindromOrNot(int number) {
	char stringOfNumbers[20];
	fromIntToString(number, stringOfNumbers);
	char reversedString = stringOfNumbers;
	reverseString(stringOfNumbers, lenghtOfString(stringOfNumbers));
	int i = 0;
	while (stringOfNumbers != '\0') {
		if (stringOfNumbers[i] != reversedString[i]) {
			return false;
		}
		i++;
	}
	return true;
}

bool test() {
	int firstNumber = 123321;
	int secondNumber = 123123;
	int thirdNumber = 3421;
	if (isNumberPolindromOrNot(firstNumber) && isNumberPolindromOrNot(secondNumber) && !isNumberPolindromOrNot(thirdNumber)) {
		return true;
	}
	return false;
}

int main(void) {
	if (!test()) {
		printf("test failed!");
	}
}