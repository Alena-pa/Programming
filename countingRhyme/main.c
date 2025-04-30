#include "test.h"
#include "list.h"
#include <stdio.h>

int main() {
    if (!test()) {
        printf("Testing error\n");
        return 1;
    }

    printf("Enter the number of warriors: ");
    int numberOfWarriors = 0;
    scanf("%d", &numberOfWarriors);

    printf("Enter killing periodicity: ");
    int periodicity = 0;
    scanf("%d", &periodicity);

    if (numberOfWarriors < 1 || periodicity < 1) {
        printf("Invalid input\n");
        return 1;
    }

    const int survivorWarrior = count(numberOfWarriors, periodicity);
    printf("Position number of survivor warrior: %d\n", survivorWarrior);
    return 0;
}