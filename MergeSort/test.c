#include <stdbool.h>
#include <stdio.h>
#include "list.h"
#include "mergeSort.h"
#include "test.h"

bool tests() {
    List* list = createList();

    char name1[10] = "z";
    char phone1[10] = "1";
    addEntry(list, name1, phone1);

    char name2[10] = "c";
    char phone2[10] = "9";
    addEntry(list, name2, phone2);

    char name3[10] = "a";
    char phone3[10] = "4";
    addEntry(list, name3, phone3);

    char name4[10] = "h";
    char phone4[10] = "2";
    addEntry(list, name4, phone4);

    List* sortedList1 = mergeSort(list, 1);
    bool testsPassed = checkSort(sortedList1, true);

    List* sortedList2 = mergeSort(sortedList1, 0);
    testsPassed = testsPassed && checkSort(sortedList2, false);

    deleteList(sortedList2);

    return testsPassed;
}
