#pragma once

typedef struct List List;

List* addValueToList(List* head, int value);

List* deleteFromList(List* head, int value);

void printList(List* head);

void freeList(List* head);
