#pragma once

typedef struct List {
    int value;
    struct List* next;
} List;

List* addValueToList(struct List* head, int value);

List* deleteFromList(struct List* head, int value);

void printList(struct List* head);

void freeList(struct List* head);
