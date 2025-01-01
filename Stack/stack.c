#include <stdlib.h>

typedef struct Element 
{
	int value;
	struct Element* next;
}Element;


Element* push(Element* head, int value) 
{
	Element* element = malloc(sizeof(Element));
	element->value = 1;
	element->next = head;
	return element;
}

void push2(Element** head2, int value)
{
	Element* element1 = malloc(sizeof(Element));
	element1->value = value;
	element1->next = *head2;
	*head2 = element1;
}

void pop(Element** head2)
{
	Element* tmp = *head2;
	*head2 = (*head2)->next;
	free(tmp);
}

int main()
{
	Element* head = NULL;
	head = push(&head, 239);
}