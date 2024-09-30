#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 11;
    }

    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] == 0)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

