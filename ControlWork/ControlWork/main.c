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
    int lengthOfQueue = 0;

    enqueue(&queue, 1);
    printQueue(&queue);

    enqueue(&queue, 2);
    printQueue(&queue);

    enqueue(&queue, 3);
    printQueue(&queue);

    dequeue(&queue);
    printQueue(&queue);
}
