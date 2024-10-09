#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* reverse(char *arrayOfWords)
{
    int lenghtOfArray = strlen(arrayOfWords);
    char* reversedArrayOfWords = (char*)malloc(sizeof(char) * (lenghtOfArray + 1));
    for (int i = 0; i < lenghtOfArray; i++)
    {
        reversedArrayOfWords[i] = arrayOfWords[lenghtOfArray - i - 1];
    }
    reversedArrayOfWords[lenghtOfArray] = '\0';
    return reversedArrayOfWords;
}

bool check(char *arrayOfWords)
{
    char *reversedArrayOfWords = reverse(arrayOfWords);
    if (strcmp(arrayOfWords, reversedArrayOfWords) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool test()
{
    char string[] = "AB bA";
    check(string);
    if (!check)
    {
        return false;
    }
    return true;
}
int main()
{
    if (!test())
    {
        printf("Smth went wrong :(");
    }
    else
    {
        char string[] = "Ab bA";
        if (!check(string))
        {
            printf("This is NOT the palindrome");
        }
        else
        {
            printf("This is the palindrome");
        }
    }
}