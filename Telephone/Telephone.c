#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_OF_NAME 80
#define MAX_SIZE_OF_PHONE 20
#define MAX_NUM_OF_RECORDS 100
#define BUFSIZE 128

typedef struct Record {
    char name[MAX_SIZE_OF_NAME + 1];
    char phone[MAX_SIZE_OF_PHONE + 1];
} Record;

int readFromFile(Record* records) {
    FILE* database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Unable to open file");
        return -1;
    }
    char name[MAX_SIZE_OF_NAME] = {0};
    char phone[MAX_SIZE_OF_PHONE] = {0};
    int numRecords = 0;
    for (int line = 0; line < MAX_NUM_OF_RECORDS; line++) {
        //Read name
        int wordsRead = fscanf(database, "%80s", name);
        if (wordsRead == EOF) {
            break;
        }
        //Read phone
        wordsRead = fscanf(database, "%20s", phone);
        if (wordsRead == EOF) {
            break;
        }
        printf("%d", line);
        printf("Name: %s Phone: %s\n", name, phone);
        numRecords++;
        fscanf(database, "%s", records[line].name);
        fscanf(database, "%s", records[line].phone);
        printf("Name: %s Phone: %s\n", records[line].name, records[line].phone);
    }
    fclose(database);
    return numRecords;
}

void printAllRecords(Record *records, int numberOfRecords) {
    for (int i = 0; i < numberOfRecords; i++) {
        printf("Name: %s Phone: %s\n", records[i].name, records[i].phone);
    }
}

void writeToRecord(Record* records, int *numberOfRecords) {
    if (*numberOfRecords >= 100) {
        printf("Too many names and numbers\n");
        return;
    }
    printf("Enter name: ");
    scanf("%80s", records[*numberOfRecords].name);
    printf("Enter phone number: ");
    scanf("%20s", records[*numberOfRecords].phone);
    (*numberOfRecords)++;
}

int SaveNameAndPhone(Record *records, int numberOfRecords) {
    FILE* database = fopen("database.txt", "w");
    if (database == NULL) {
        printf("File not found!\n");
        return 1;
    }
    for (int i = 0; i < numberOfRecords; i++) {
        fprintf(database, "%s %s\n", records[i].name, records[i].phone);
    }
    fclose(database);
    return 0;
}

void findPhoneByName(Record *records, int numerOfRecords) {
    char nameToFind[80] = { 0 };
    printf("Enter the name whose phone number you want to find: ");
    scanf("%s", nameToFind, 80);
    for (int i = 0; i < numerOfRecords; i++) {
        if (!strcmp(nameToFind, records[i].name)) {
            printf("Phone: %s\n", records[i].phone);
            return;
        }
    }
    printf("Can`t find phone\n");
}

char* findNameByPhone(Record *records, int numberOfRecords) {
    char phoneToFind[20] = { 0 };
    printf("Enter the phone number by which you want to find the name: ");
    scanf("%s", phoneToFind, 20);
    for (int i = 0; i < numberOfRecords; i++) {
        if (!strcmp(phoneToFind, records[i].phone)) {
            printf("Name: %s\n", records[i].name);
            return;
        }
    }
    printf("Can`t find name\n");
}

void printInstructionToProgram() {
    printf("0 - end the programm\n");
    printf("1 - add name and phone to database\n");
    printf("2 - printf all records\n");
    printf("3 - find phone by name\n");
    printf("4 - find name by phone\n");
    printf("5 - save\n");
    printf("Enjoy!\n");
}

int main() {
    int operationNumber = -1;
    Record records[MAX_NUM_OF_RECORDS];
    int numberOfRecords = readFromFile(records);
    if (numberOfRecords == -1) {
        return 1;
    }
    printInstructionToProgram();
    while (operationNumber != 0) {
        printf("Print number of operation: ");
        scanf("%d", &operationNumber, 1);
        switch (operationNumber) {
        case 0: 
            printf("This is the end of the programm!\n");
            break;
        case 1:
            writeToRecord(records, &numberOfRecords);
            break;
        case 2:
            printAllRecords(records, numberOfRecords);
            break;
        case 3:
            findPhoneByName(records, numberOfRecords);
            break;
        case 4:
            findNameByPhone(records, numberOfRecords);
            break;
        case 5:
            if (!SaveNameAndPhone(records, numberOfRecords)) {
                printf("Data saved\n");
            }
            else {
                printf("First you need to add some data\n");
            }
            break;
        default:
            printf("Incorrect number of operation =(\nenter number from 0 to 5 =)\n");
        }
    }
    return 0;
}