#pragma once

#define MAXSIZE_NAME 80
#define MAXSIZE_PHONE 20

typedef struct Record {
    char name[MAXSIZE_NAME];
    char phone[MAXSIZE_PHONE];
    struct Record* next;
} Record;

Record* split(struct Record* head);

Record* merge(struct Record* firstList, struct Record* secondList, int variationOfSorting);

Record* addRecord(struct Record* head, const char* name, const char* phone);

int compareByName(struct Record* firstName, struct Record* secondName);

int compareByPhone(struct Record* firstPhone, struct Record* secondPhone);

Record* readRecordsFromFile(const char* fileName);

void printList(struct Record *head);

void freeList(struct Record* head);