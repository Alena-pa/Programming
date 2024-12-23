#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void foundInFile(FILE* file) {
    FILE* output = fopen("output.txt", "w");
    bool isComment = false;
    int symbol = fgetc(file);
    while (symbol != EOF) {
        if (symbol == ';') {
            isComment = true;
        }
        if (isComment) {
            putc(symbol, output);
        }
        if (symbol == '\n') {
            putc('\n', output);
            isComment = false;
        }
        symbol = fgetc(file);
    }
    fclose(output);
}

int main(void) {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }
    foundInFile(file);
    fclose(file);
}