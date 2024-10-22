#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[80];
    char phone[20];
} Record;

void printArray(int* arrayOfIntegers, int lenghtOfArray)
{
    for (int i = 0; i < lenghtOfArray; i++)
        printf("%s ", arrayOfIntegers[i]);
    printf("\n");
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
    return "Nothing found";
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
    return "Nothing found";
}

int main()
{
	int operationNumber = -1;
    FILE* database = fopen("database.txt", "a+");
    if (database == NULL)
    {
        printf("can`t open the file\n");
        return 1;
    }
	while (operationNumber != 0)
	{
		printf("Print number of operation: ");
		scanf("%d", &operationNumber);
		switch (operationNumber)
		{
		case 0: 
			break;
		case 1:
			printf("1\n");
			break;
		case 2:
			printf("2\n");
			break;
		case 3:
			printf("3\n");
			break;
		case 4:
			printf("4\n");
			break;
		case 5:
			printf("5\n");
			break;
		default:
			printf("Incorrect number of operation =(\nenter number from 0 to 5 =)\n");
		}
	}
	return 0;
}