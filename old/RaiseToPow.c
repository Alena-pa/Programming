#include <math.h>
#include <stdio.h>
#include <stdbool.h>

double simpleRaiseToPow(int number, int pow) {
    double answer = 1;
    int absPow = abs(pow);
    for (int i = 0; i < absPow; i++) {
        answer *= number;
    }
    if (pow < 0) {
        return 1 / answer;
    }
    else {
        return answer;
    }
}

double upgradeRaiseToPow(int number, int pow) {
    double answer = 1;
    int absPow = abs(pow);
    while (absPow) {
        if (absPow % 2 == 0) {
            absPow /= 2;
            number *= number;
        }
        else {
            absPow--;
            answer *= number;
        }
    }
    if (pow < 0) {
        return 1 / answer;
    }
    else {
        return answer;
    }
}

bool areEqual(double firstNumber, double secondNumber, double epsilon) {
	return fabs(firstNumber - secondNumber) < epsilon;
}

bool testSimpleRaise() {
	double epsilon = 1e-6;
	return areEqual(simpleRaiseToPow(2, 2), 4, epsilon) && 
            areEqual(simpleRaiseToPow(2, 0), 1, epsilon) && 
            areEqual(simpleRaiseToPow(-2, 1), -2, epsilon) &&
            areEqual(simpleRaiseToPow(2, -1), 0.5, epsilon) && 
            areEqual(simpleRaiseToPow(-2, 2), 4, epsilon);
}

bool testUpgradeRaise() {
	double epsilon = 1e-6;
    return areEqual(upgradeRaiseToPow(2, 2), 4, epsilon) && 
            areEqual(upgradeRaiseToPow(2, 0), 1, epsilon) && 
            areEqual(upgradeRaiseToPow(-2, 2), 4, epsilon) &&
            areEqual(upgradeRaiseToPow(2, -1), 0.5, epsilon);
}

int main() {
    if (!testSimpleRaise() && !testUpgradeRaise()) {
        printf("Smth Went Wrong!\n");
        return -1;
    }
}
