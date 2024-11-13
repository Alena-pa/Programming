#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE_NAME 80
#define MAXSIZE_PHONE 20


struct Record{
    char name[MAXSIZE_NAME];
    char phone[MAXSIZE_PHONE];
    struct Record* next;
} Record;

struct Record* split(struct Record* head){
    struct Record* fast = head;
    struct Record* slow = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if (fast != NULL){
            slow = slow->next;
        }
    }
    struct Record* temp = slow->next;
    slow->next = NULL;
    return temp;
} 

struct Record* merge(struct Record* firstList, struct Record* secondList, int variationOfSorting){
    if (firstList == NULL){
        return secondList;
    }
    if (secondList == NULL){
        return firstList;
    }
    if (){

    }
}

int main(void){
    struct Record(*variationOfSorting)(int) = &merge;
    return 0;
}