#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[80];
    char phone[20];
} Record;

int readFromFile(Record **record, int *numberOfRecords)
{
    FILE* database = fopen("database.txt", "r");
    int howMuchLinesRead = 0;
    while (howMuchLinesRead < 100)
    {
        char* buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL)
        {
            printf("Not enough memory");
            return 1;
        }
        
        if (fgets(buffer, 100, database) == NULL)
        {
            free(buffer);
            break;
        }
        else
        {
            buffer[strcspn(buffer, "\n")] = 0;
            Record* tempMemory = malloc(sizeof(Record));
            if (tempMemory == NULL)
            {
                printf("Not enough memory");
                return 1;
            }
            size_t indexOfTheSpace = strcspn(buffer, " ");
            for (int i = 0; i < indexOfTheSpace; i++)
            {
                tempMemory->name[i] = buffer[i];
            }
            int i = 0;
            for (int j = indexOfTheSpace + 1; j < strlen(buffer); j++)
            {
                tempMemory->phone[i] = buffer[j];
                j++;
            }
            record[howMuchLinesRead] = tempMemory;
            howMuchLinesRead++;
        }
    }
    fclose(database);
    *numberOfRecords = howMuchLinesRead;
    return 0;
}
void printAllRecords(Record *record, int numberOfRecords)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        printf("Name: %s\nPhone: %s\n", record[i].name, record[i].phone);
    }
    return;
}


int appendNameAndPhone(Record **record, int numberOfRecords, bool *ifDataChangedOrNot)
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
        fprintf(database, "%s %s\n", record[i]->name, record[i]->phone);
        numberOfRecords++;
    }
    fclose(database);
    *ifDataChangedOrNot = false;
    return 0;
}

char* findPhoneByName(Record **record, int numerOfRecords, char *nameToFound)
{
    for (int i = 0; i < numerOfRecords; i++)
    {
        if (!strcmp(nameToFound, record[i]->name))
        {
            return record[i]->phone;
        }
    }
    return NULL;
}

char* findNameByPhone(Record **record, int numberOfRecords, char *phoneToFound)
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        if (!strcmp(phoneToFound, record[i]->phone))
        {
            return record[i]->name;
        }
    }
    return NULL;
}

int main()
{
	int operationNumber = -1;
    int numberOfRecords = 0;
    FILE* database = fopen("database.txt", "a+");
    if (database == NULL)
    {
        printf("can`t open the file\n");
        return 1;
    }
    Record* record[100];
    bool ifDataChangedOrNot = false;
	while (operationNumber != 0)
	{
		printf("Print number of operation: ");
		scanf("%d", &operationNumber);
		switch (operationNumber)
		{
		case 0: 
            for (int i = 0; i < numberOfRecords; i++)
            {
                free(record[i]);
            }
            printf("This is the end of the programm!\n");
            return 0;
		case 1:
            if (numberOfRecords >= 100)
            {
                printf("Too many names and numbers");
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
            }
		case 2:
            printAllRecords(record, numberOfRecords);
		case 3:
            char nameToFound[80];
            printf("Enter the name whose phone number you want to find: ");
            scanf_s("%s", nameToFound, 80);
            findPhoneByName(record, numberOfRecords, nameToFound);
		case 4:
            char phoneToFound[20];
            printf("Enter the phone number by which you want to find the name: ");
            scanf_s("%s", phoneToFound, 20);
            findNameByPhone(record, numberOfRecords, phoneToFound);
		case 5:
            if (!writeToFile(database, database, numberOfRecords, &ifDataChangedOrNot)) {
                printf("Data saved\n");
            }
            else {
                printf("First you need to add some data\n");
		default:
			printf("Incorrect number of operation =(\nenter number from 0 to 5 =)\n");
		}
	}
	return 0;
}