#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void foundInFile(FILE* file) {
    bool isComment = false;
    int symbol = fgetc(file);
    while (symbol != EOF) {
        if (symbol == ';') {
            isComment = true;
        }
        if (isComment) {
            putc(symbol, stdout);
        }
        if (symbol == '\n') {
            putc('\n', stdout);
            isComment = false;
        }
        symbol = fgetc(file);
    }
}

int main(void) {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }
    foundInFile(file);
}