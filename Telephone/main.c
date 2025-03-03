#include "test.h"
#include "telephone.h"
#include <stdio.h>

int main() {
    if (!allTests()) {
        printf("Tests failed!");
        return - 1;
    }
    int operationNumber = -1;
    Record* records[100] = {NULL};
    int numberOfRecords = readFromFile(records);
    char nameToFind[80] = { 0 };
    char phoneToFind[20] = { 0 };
    int errorCode = 0;
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
            printf("Enter the name whose phone number you want to find: ");
            scanf("%s", nameToFind, 80);
            if (!findPhoneByName(records, numberOfRecords, nameToFind)) {
                printf("Can`t find phone\n");
            }
            break;
        case 4:
            printf("Enter the phone number by which you want to find the name: ");
            scanf("%s", phoneToFind, 20);
            if (!findNameByPhone(records, numberOfRecords, phoneToFind)) {
                printf("Can`t find name\n");
            }
            break;
        case 5:
            if (SaveNameAndPhone(records, numberOfRecords, &errorCode)) {
                printf("Data saved\n");
            }
            else {
                if (errorCode == -1) {
                    printf("unable to open file");
                    return -1;
                }
                printf("First you need to add some data\n");
            }
            break;
        default:
            printf("Incorrect number of operation =(\nenter number from 0 to 5 =)\n");
        }
    }
    return 0;
}