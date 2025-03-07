#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

typedef struct List {
    int value;
    struct List* next;
} List;

List* addValueToList(List* head, int value) {
    List* valueToAdd = (List*)malloc(sizeof(List));
    if (valueToAdd == NULL) {
        return NULL;
    }
    valueToAdd->value = value;
    valueToAdd->next = NULL;

    if (head == NULL || head->value >= value) {
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

List* deleteFromList(List* head, int value) {
    if (head == NULL) {
        return NULL;
    }
    List* currentElementOfList = head;

    while (currentElementOfList->next && currentElementOfList->next->value != value) {
        currentElementOfList = currentElementOfList->next;
    }

    if (currentElementOfList->next == NULL) {
        return head;
    }
    currentElementOfList->next = currentElementOfList->next->next;
    return head;
}

void printList(List* head) {
    List* currentElementOfList = head;
    printf("List:\n");
    while (currentElementOfList) {
        printf("%d ", currentElementOfList->value);
        currentElementOfList = currentElementOfList->next;
    }
    printf("\n");
}

void freeList(List* head) {
    while (head) {
        List* elementToFree = head;
        head = head->next;
        free(elementToFree);
    }
}

int getValueFromList(List* head) {
    return head->value;
}

int switchValueToNext(List* head) {
    return head->next->value;
}