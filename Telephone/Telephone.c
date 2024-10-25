#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_OF_NAME 80
#define MAX_SIZE_OF_PHONE 20
#define MAX_NUM_OF_RECORDS 100
#define BUFSIZE 128

typedef struct
{
    char name[MAX_SIZE_OF_NAME + 1];
    char phone[MAX_SIZE_OF_PHONE + 1];
} Record;

int readFromFile(Record *record)
{
    FILE* database = fopen("database.txt", "r");
    int line;
    char buffer[BUFSIZE];
    for (line = 0; line < MAX_NUM_OF_RECORDS; line++)
    {
        memset(record[line].name, 0, sizeof(record[line].name));
        memset(record[line].phone, 0, sizeof(record[line].phone));
        //Read name
        int words_read = fscanf(database, "%s", buffer);
        if (words_read == EOF)
        {
            break;
        }
        strncpy(record[line].name, buffer, MAX_SIZE_OF_NAME);
        
        //Read phone
        words_read = fscanf(database, "%s", buffer);
        if (words_read == EOF)
        {
            break;
        }
        strncpy(record[line].phone, buffer, MAX_SIZE_OF_PHONE);
        printf("Name: %s Phone: %s\n", record[line].name, record[line].phone);
    }
    fclose(database);
    return line;
}
void printAllRecords(Record *record, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        printf("Name: %s Phone: %s\n", record[i].name, record[i].phone);
    }
    return;
}

int SaveNameAndPhone(Record *record, int numberOfRecords, bool *ifDataChangedOrNot)
{
    if (!*ifDataChangedOrNot)
    {
        return 2;
    }
    FILE* database = fopen("database.txt", "w");
    if (database == NULL) {
        printf("File not found!\n");
        return 1;
    }
    for (int i = 0; i < numberOfRecords; i++)
    {
        fprintf(database, "%s %s\n", record[i].name, record[i].phone);
        numberOfRecords++;
    }
    fclose(database);
    *ifDataChangedOrNot = false;
    return 0;
}

void findPhoneByName(Record *record, int numerOfRecords)
{
    char nameToFind[80];
    printf("Enter the name whose phone number you want to find: ");
    scanf_s("%s", nameToFind, 80);
    for (int i = 0; i < numerOfRecords; i++)
    {
        if (!strcmp(nameToFind, record[i].name))
        {
            printf("Phone: %s\n", record[i].phone);
        }
    }
}

char* findNameByPhone(Record *record, int numberOfRecords)
{
    char phoneToFind[20];
    printf("Enter the phone number by which you want to find the name: ");
    scanf_s("%s", phoneToFind, 20);
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (!strcmp(phoneToFind, record[i].phone))
        {
            printf("Name: %s\n", record[i].name);
        }
    }
}

void printInstructionToProgram()
{
    printf("0 - end the programm\n");
    printf("1 - add name and phone to database\n");
    printf("2 - printf all records\n");
    printf("3 - find phone by name\n");
    printf("4 - find name by phone\n");
    printf("5 - save\n");
    printf("Enjoy!\n");
}

int main()
{
	int operationNumber = -1;
    Record* record[100];
    int numberOfRecords = readFromFile(record);
    bool ifDataChangedOrNot = false;
    printInstructionToProgram();
	while (operationNumber != 0)
	{
		printf("Print number of operation: ");
		scanf_s("%d", &operationNumber, 1);
		switch (operationNumber)
		{
		case 0: 
            for (int i = 0; i < numberOfRecords; i++)
            {
                free(record[i]);
            }
            printf("This is the end of the programm!\n");
            break;
		case 1:
            if (numberOfRecords >= 100)
            {
                printf("Too many names and numbers");
                break;
            }
            else
            {
                Record* tempMemory = malloc(sizeof(Record));
                if (tempMemory == NULL)
                {
                    printf("Not enough memory");
                    return 1;
                }
                printf("Enter name: ");
                scanf_s("%s", tempMemory->name, 80);
                printf("Enter phone number: ");
                scanf_s("%s", tempMemory->phone, 20);
                record[numberOfRecords] = tempMemory;
                numberOfRecords++;
                ifDataChangedOrNot = true;
                break;
            }
		case 2:
            printAllRecords(record, numberOfRecords);
            break;
		case 3:
            findPhoneByName(record, numberOfRecords);
            break;
		case 4:
            findNameByPhone(record, numberOfRecords);
            break;
		case 5:
            if (!SaveNameAndPhone(record, numberOfRecords, &ifDataChangedOrNot))
            {
                printf("Data saved\n");
            }
            else
            {
                printf("First you need to add some data\n");
            }
            break;
		default:
			printf("Incorrect number of operation =(\nenter number from 0 to 5 =)\n");
		}
	}
	return 0;
}