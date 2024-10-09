#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void removeSpaces(char *arrayOfWords) 
{
    int i, j = 0;
    for (i = 0; arrayOfWords[i] != '\0'; i++)
    {
        if (arrayOfWords[i] != ' ')
        {
            arrayOfWords[j] = arrayOfWords[i];
            j++;
        }
    }
    arrayOfWords[j] = '\0';
}

void reverse(char *arrayOfWords)
{
    int firstIndex = 0;
    int lastIndex = strlen(arrayOfWords) - 1;
    char letter;
    while (firstIndex < lastIndex)
    {
        letter = arrayOfWords[firstIndex];
        arrayOfWords[firstIndex] = arrayOfWords[lastIndex];
        arrayOfWords[lastIndex] = letter;
        
        firstIndex++;
        lastIndex--;
    }
}

bool check(char *arrayOfWords)
{
    removeSpaces(arrayOfWords);
    char *reversedArrayOfWords = arrayOfWords;
    reverse(reversedArrayOfWords);
    for (int i = 0; i < strlen(arrayOfWords); i++)
    {
        if (arrayOfWords[i] != reversedArrayOfWords[i])
        {
            return false;
        }
    }
    return true;
}

bool test()
{
    char string[] = "Ab bA";
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