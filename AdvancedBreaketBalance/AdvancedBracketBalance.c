#include <stdio.h>
#include <stdbool.h>
#include "StackForBracketBalance.h"

int advancedBracketBalance(char* brackets)
{
    Stack* stack = createStack();
    int bracketsRead = 0;
    while (brackets[bracketsRead] != EOF)
    {
        switch (brackets[bracketsRead])
        {
        case '(':
     push(stack, "(");
     break;
        case ')':
    if (theLastElementOfStack(stack) != 1 && theLastElementOfStack(stack) == "(")
    {
        pop(stack);
        break;
    }
    else
    {
        return 1;
    }
        case '{':
     push(stack, "{");
     break;
        case '}':
     if (theLastElementOfStack(stack) != 1 && theLastElementOfStack(stack) == "{")
     {
         pop(stack);
         break;
     }
     else
     {
         return 1;
     }
        case '[':
     push(stack, "[");
     break;
        case ']':
     if (theLastElementOfStack(stack) != 1 && theLastElementOfStack(stack) == "[")
     {
         pop(stack);
         break;
     }
     else
     {
         return 1;
     }
        default:
            break;
        }
        bracketsRead++;
    }
    if (theLastElementOfStack(stack) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool test()
{
    char string1 = "{){}";
    char string2 = "}{";
    char string3 = "[]{}({})";
    if (advancedBracketBalance(string1) == 1 && advancedBracketBalance(string2) == 1 && advancedBracketBalance(string3) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    if (!test)
    {
        printf("Test Failed!");
        return 1;
    }
    char stringOfBrackets[100];
    printf("Enter string of brackets: ");
    scanf_s("%s", stringOfBrackets, 100);
}