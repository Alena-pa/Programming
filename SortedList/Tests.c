#include <stdbool.h>
#include <stdio.h>
#include "Tests.h"
#include "SortedList.h"

typedef struct List {
    int value;
    struct List* next;
} List;

bool testAddValueToList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);
    bool result = (list->value == 1 && list->next->value == 2 && list->next->next->value == 3);
    freeList(list);
    return result;
}

bool testDeleteHeadFromList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);

    list = deleteFromList(list, 1);
    bool result = list->value == 2 && list->next->value == 3;
    freeList(list);
    return result;
}

bool testDeleteElementFromList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);

    list = deleteFromList(list, 2);
    bool result = (list->value == 1 && list->next->value == 3);
    freeList(list);
    return result;
}

bool allTests(void) {
    return testAddValueToList && testDeleteElementFromList && testDeleteHeadFromList;
}