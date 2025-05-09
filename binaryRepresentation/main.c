#include "binaryRepresentation.h"
#include <stdio.h>
#include "test.h"
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Rus");
    if (!test()) {
        printf("Тест Завален!!!");
        return -1;
    }

    answer(5, 1);
    answer(4, 8);
}