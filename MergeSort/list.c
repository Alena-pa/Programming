#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char* name;
    char* phone;
    struct Node* next;
} Node;

typedef struct List {
    int length;
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    newList->length = 0;
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

int isEmpty(List* list) {
    return list->head == NULL;
}

void addEntry(List* list, const char* name, const char* phone) {
    list->length++;

    char* newName = (char*)malloc(strlen(name) + 1);
    char* newPhone = (char*)malloc(strlen(phone) + 1);

    strcpy(newName, name);
    strcpy(newPhone, phone);

    Node* newEntry = (Node*)malloc(sizeof(Node));
    newEntry->name = newName;
    newEntry->phone = newPhone;
    newEntry->next = NULL;

    if (isEmpty(list)) {
        list->head = newEntry;
        list->tail = newEntry;
    }
    else {
        list->tail->next = newEntry;
        list->tail = newEntry;
    }
}

char* returnNameFromHead(List* list) {
    return list->head->name;
}

char* returnPhoneFromHead(List* list) {
    return list->head->phone;
}

int listLength(List* list) {
    return list->length;
}

void deleteHead(List* list) {
    if (isEmpty(list)) {
        return;
    }

    list->length--;
    Node* temp = list->head->next;

    free(list->head->name);
    free(list->head->phone);
    free(list->head);

    list->head = temp;
}

bool checkSort(List* list, bool byName) {
    if (isEmpty(list)) {
        return true;
    }

    Node* current = list->head->next;
    Node* previous = list->head;

    while (current != NULL) {
        int comparison = 0;
        if (byName) {
            comparison = strcmp(current->name, previous->name);
        }
        else {
            comparison = strcmp(current->phone, previous->phone);
        }

        if (comparison < 0) {
            return false;
        }
        previous = current;
        current = current->next;
    }

    return true;
}

void printList(List* list) {
    if (isEmpty(list)) {
        return;
    }

    Node* current = list->head;
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->phone);
        current = current->next;
    }
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        Node* temp = list->head->next;

        free(list->head->name);
        free(list->head->phone);
        free(list->head);

        list->head = temp;
    }

    free(list);
}
