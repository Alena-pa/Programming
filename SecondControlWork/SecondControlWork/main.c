#include "trasitiveClosure.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error at opening file");
        return;
    }

    fscanf(input, "%d", &n);

    int** relation = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        relation[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(input, "%d", &relation[i][j]);
        }
    }

    fclose(input);

    transitiveClosure(n, relation);
    writeOutput("output.txt", n, relation);

    for (int i = 0; i < n; i++) {
        free(relation[i]);
    }
    free(relation);
}