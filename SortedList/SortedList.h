#pragma once

typedef struct List List;

// adding value to list
List* addValueToList(List* head, int value);

// deleting value from list
List* deleteFromList(List* head, int value);

// printing list
void printList(List* head);

// delete list
void freeList(List* head);

// get last value from list
int getValueFromList(List* head);

// moving value to next value
int switchValueToNext(List* head);
