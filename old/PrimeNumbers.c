#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkIfNumberPrimeOrNot(int number){
	if (number <= 1){
		return false;
	}
	else if (number == 2){
		return true;
	}
	else if(number % 2 == 0){
		return false;
	}

	int lastNumberToCheck = (int)sqrt(number);
	for (int i = 3; i <= lastNumberToCheck; i += 2){
		if (number % i == 0){
			return false;
		}
	}

	return true;
}

void printPrimeNumbers(int number){
	for (int i = 0; i <= number; i++){
		if (checkIfNumberPrimeOrNot(i)){
			printf("%d\n", i);
		}
	}
}

int main(void){
	printPrimeNumbers(65);
}