#include <stdbool.h>
#include <stdio.h>
#include "Tests.h"
#include "SortedList.h"

bool testAddValueToList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);

    int firstValue = getValueFromList(list);
    int secondValue = switchValueToNext(firstValue);
    int thirdValue = switchValueToNext(secondValue);

    bool result = firstValue == 1 && secondValue == 2 && thirdValue == 3;
    freeList(list);
    return result;
}

bool testDeleteHeadFromList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);

    list = deleteFromList(list, 1);

    int firstValue = getValueFromList(list);
    int secondValue = switchValueToNext(firstValue);

    bool result = firstValue == 2 && secondValue == 3;
    freeList(list);
    return result;
}

bool testDeleteElementFromList(void) {
    List* list = NULL;
    list = addValueToList(list, 1);
    list = addValueToList(list, 2);
    list = addValueToList(list, 3);

    list = deleteFromList(list, 2);


    int firstValue = getValueFromList(list);
    int secondValue = switchValueToNext(firstValue);

    bool result = firstValue == 1 && secondValue == 3;
    freeList(list);
    return result;
}

bool allTests(void) {
    return testAddValueToList() && testDeleteElementFromList() && testDeleteHeadFromList();
}