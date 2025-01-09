#pragma once
#include <stdbool.h>

typedef struct List List;

List* createList();

void addEntry(List* list, char* name, char* phone);

char* returnNameFromHead(List* list);

char* returnPhoneFromHead(List* list);

int listLength(List* list);

void deleteHead(List* list);

bool checkSort(List* list, bool byName);

void printList(List* list);

void deleteList(List* list);