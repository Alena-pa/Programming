#pragma once
#include <stdio.h>
void readInput(FILE* file, int* n, int relation[*][*]);

void writeOutput(FILE* file, int n, int relation[n][n]);

void transitiveClosure(int n, int relation[n][n]);