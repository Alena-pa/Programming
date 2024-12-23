#include <stdio.h>
#include <stdlib.h>
#include "trasitiveClosure.h"

void writeOutput(char* filename, int n, int** relation) {
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

void transitiveClosure(int n, int** relation) {
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