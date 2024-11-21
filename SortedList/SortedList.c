#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

List* addValueToList(struct List* head, int value) {
    List* valueToAdd = (List*)malloc(sizeof(List));
    if (!valueToAdd) {
        printf("Not enough memory!");
        return head;
    }
    valueToAdd->value = value;
    valueToAdd->next = NULL;

    if (!head || head->value >= value) {
        valueToAdd->next = head;
        return valueToAdd;
    }

    List* currentElementOfList = head;
    while (currentElementOfList->next && currentElementOfList->next->value < value) {
        currentElementOfList = currentElementOfList->next;
    }

    valueToAdd->next = currentElementOfList->next;
    currentElementOfList->next = valueToAdd;

    return head;
}

List* deleteFromList(struct List* head, int value) {
    List* currentElementOfList = head;
    while (currentElementOfList->next && currentElementOfList->next->value != value) {
        currentElementOfList = currentElementOfList->next;
    }

    if (currentElementOfList->next == NULL) {
        printf("Didn`t found value %d at list\n", value);
        return head;
    }
    currentElementOfList->next = currentElementOfList->next->next;
    printf("Value %d deleted\n", value);
    return head;
}

void printList(struct List* head) {
    List* currentElementOfList = head;
    printf("List:\n");
    while (currentElementOfList) {
        printf("%d ", currentElementOfList->value);
        currentElementOfList = currentElementOfList->next;
    }
    printf("\n");
}

void freeList(struct List* head) {
    while (head) {
        List* elementToFree = head;
        head = head->next;
        free(elementToFree);
    }
}