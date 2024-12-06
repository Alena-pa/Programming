#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double raiseToPowSimple(int number, int pow) {
    double answer = 1;
    int absPow = abs(pow);
    for (int i = 0, i < absPow, i++) {
        answer *= number;
    }

    return pow < 0 ? 1 / answer : answer;
}

double raiseToPowUpgraded(int number, int pow) {
    double answer = 1;
    int absPow = abs(pow);
    while (absPow != 0) {
        if (absPow % 2 == 0) {
            absPow /= 2;
            answer *= number;
        }
        else {
            absPow--;
            answer *= number;
        }
    }
    
    return pow < 0 ? 1 / answer : answer;
}

bool testSimpleRaise() {
    return ((simpleRaiseToPow(2, 2) == 4) && (simpleRaiseToPow(2, 0) == 1) && (simpleRaiseToPow(-2, 1) == -2)
        && (simpleRaiseToPow(2, -1) == 0, 5) && (simpleRaiseToPow(-2, 2) == 4));
}

bool testUpgradeRaise() {
    return ((upgradeRaiseToPow(2, 2) == 4) && (upgradeRaiseToPow(2, 0) == 1) && (upgradeRaiseToPow(-2, 2) == 4)
        && (upgradeRaiseToPow(2, -1) == 0, 5));
}
int main(void) {
    if (!testSimpleRaise() && !testUpgradeRaise()){
        printf("Smth Went Wrong!\n");
        return 1;
    }
    return 0;
}
