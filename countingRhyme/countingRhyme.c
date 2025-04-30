#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    if (!newList) {
        return NULL;
    }
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

bool onlyHeadInList(List* list) {
    return list->head == list->tail;
}

int headValue(List* list) {
    if (isEmpty(list)) {
        return -1;
    }
    return list->head->value;
}

void addValue(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(list)) {
        list->head = newNode;
        list->head->next = list->head;
        list->tail = list->head;
    }
    else {
        list->tail->next = newNode;
        newNode->next = list->head;
        list->tail = newNode;
    }
}

void deleteValue(List* list, int positionNumber) {
    if (isEmpty(list)) {
        return;
    }

    Node* current = list->head;
    Node* previous = list->tail;

    for (int i = 1; i < positionNumber; ++i) {
        previous = current;
        current = current->next;
        if (current == list->head) {
            return;
        }
    }

    if (current == list->head) {
        list->head = current->next;
    }
    if (current == list->tail) {
        list->tail = previous;
    }

    previous->next = current->next;
    free(current);
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        deleteValue(list, 1);
    }
    free(list);
}

int count(int numberOfWarriors, int periodicity) {
    List* list = createList();
    for (int i = 1; i <= numberOfWarriors; ++i) {
        addValue(list, i);
    }

    while (!onlyHeadInList(list)) {
        deleteValue(list, periodicity);
    }

    const int survivorWarrior = headValue(list);
    deleteList(list);
    return survivorWarrior;
}