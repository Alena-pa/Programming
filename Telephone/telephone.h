#pragma once
#include <stdbool.h>

typedef struct Record Record;

// Function to read data from a file
int readFromFile(Record* records);

// Function to print all records to the console
void printAllRecords(Record* records, int numberOfRecords);

// Function to add a new record
void writeToRecord(Record* records, int* numberOfRecords);

// Function to save records to a file
bool SaveNameAndPhone(Record* records, int numberOfRecords, int* errorCode);

// Function to find a phone number by name
bool findPhoneByName(Record* records, int numberOfRecords, char* nameToFound);

// Function to find a name by phone number
bool findNameByPhone(Record* records, int numberOfRecords, char* phoneToFound);

// Function to display instructions to the user
void printInstructionToProgram();