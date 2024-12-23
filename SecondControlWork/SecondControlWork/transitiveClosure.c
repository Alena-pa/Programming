#include <stdio.h>

void readInput(char* filename, int* n, int relation[*][*]) {
    FILE* input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error at opening file");
        return;
    }

    fscanf(input, "%d", n);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(input, "%d", &relation[i][j]);
        }
    }

    fclose(input);
}

void writeOutput(char* filename, int n, int relation[n][n]) {
    FILE* output = fopen(filename, "w");
    if (output == NULL) {
        printf("Error at opening file");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(output, "%d ", relation[i][j]);
        }
        fprintf(output, "\n");
    }

    fclose(output);
}

void transitiveClosure(int n, int relation[n][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (relation[i][k] && relation[k][j]) {
                    relation[i][j] = 1;
                }
            }
        }
    }
}