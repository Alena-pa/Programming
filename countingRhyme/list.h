#pragma once

typedef struct List List;

List* createList();

bool onlyHeadInList(List* list);

int headValue(List* list);

void addValue(List* list, int value);

void deleteValue(List* list, int positionNumber);

void deleteList(List* list);

int count(int numberOfWarriors, int periodicity);