#include "telephone.h"
#include <stdio.h> 

typedef struct Record {
    char name[80 + 1];
    char phone[20 + 1];
} Record;


bool testReadFromFile(void) {
    Record* records[10];
    int count = readFromFile(records);
    if (count >= 0) {
        return true;
    }
    else {
        printf("Error at function readFromFile\n");
        return false;
    }
}

bool testWriteToRecord(void) {
    Record* records[10];
    int numRecords = 0;
    writeToRecord(records, &numRecords, "Alice", "12345");
    if (numRecords > 0) {
        return true;
    }
    else {
        printf("Error at function writeToRecord\n");
        return false;
    }
}

bool testSaveNameAndPhone(void) {
    Record records[2] = {
        {"Alice", "12345"},
        {"Bob", "67890"}
    };
    int errorCode = 0;
    if (SaveNameAndPhone(records, 2, &errorCode)) {
        return true;
    }
    else {
        printf("Error at function SaveNameAndPhone\n");
    }
}

bool testFindPhoneByName(void) {
    Record records[2] = {
        {"Alice", "12345"},
        {"Bob", "67890"}
    };
    if (findPhoneByName(records, 2, "Alice")) {
        return true;
    }
    else {
        printf("Error at funciton findPhoneByName\n");
        return false;
    }
}

bool testFindNameByPhone(void) {
    Record records[2] = {
        {"Alice", "12345"},
        {"Bob", "67890"}
    };
    if (findNameByPhone(records, 2, "67890")) {
        return true;
    }
    else {
        printf("Error at function findNameByPhone\n");
        return false;
    }
}

bool allTests(void) {
    return (testFindNameByPhone && testFindPhoneByName && testReadFromFile && testSaveNameAndPhone && testWriteToRecord);
}