#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"
#include "Tests.h"

int main(void) {
    if (!allTests()) {
        printf("Tests failed!\n");
        return 1;
    }
    List* list = NULL;

    printf("Instruction to programm:\n");
    printf("0 - exit\n");
    printf("1 - add value to list\n");
    printf("2 - delete value from list\n");
    printf("3 - print list\n");

    int numberOfOperation = -1;

    int value = 0;
    while (numberOfOperation != 0) {
        printf("Enter number of operation: ");
        scanf("%d", &numberOfOperation);

        switch (numberOfOperation) {
        case 0:
            freeList(list);
            printf("This is the end of program");
            return 0;
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &value);
            list = addValueToList(list, value);
            if (!list) {
                printf("Not enough memory :(");
                return -1;
            }
            printf("Value %d added\n", value);
            break;
        case 2:
            if (list != NULL) {
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (!list) {
                    return -1;
                }
                list = deleteFromList(list, value);
                if (list == NULL) {
                    printf("Didn`t found value %d at list\n", value);
                }
                else {
                    printf("Value %d deleted\n", value);
                }
            }
            else {
                printf("List is empty, press 1 to add smth to list\n");
            }

            break;
        case 3:
            if (list != NULL) {
                printList(list);
            }
            else {
                printf("List is empty, press 1 to add smth to list\n");
            }
            break;
        default:
            printf("Invalid number, enter a number from 1 to 3\n");
        }
    }
    return 0;
}