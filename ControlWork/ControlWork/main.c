#include <stdio.h>
#include "Queue.h"
#include "Tests.h"

int main(void) {
    if (!allTests) {
        printf("Tests Failed!");
        return -1;
    }
    Queue queue;
    createQueue(&queue);

    enqueue(&queue, 1);
    printQueue(&queue);

    enqueue(&queue, 2);
    printQueue(&queue);

    enqueue(&queue, 3);
    printQueue(&queue);

    int removedElement = dequeue(&queue);
    printf("Removed element from queue: %d\n", removedElement);
    printQueue(&queue);
}
