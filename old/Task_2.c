#include <stdio.h>

void swap(int* left, int* right)
{
    if (left != right)
    {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
    else
    {
        prinf("Incorrect condition!!! They are the same!");
    }
}

int main()
{
    int firstNumber = 1;
    int secondNumber = 2;
    printf("before swap: %d %d\n", firstNumber, secondNumber);
    swap(&firstNumber, &secondNumber);
    printf("after swap: %d %d", firstNumber, secondNumber);
}
