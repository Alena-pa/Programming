#include <stdio.h>

int check(char *string)
{
    int thisVarCheckingString = 0;
    if (string[0] == ')')
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < strlen(string); i++)
        {
            if (string[i] == '(')
            {
                thisVarCheckingString++;
            }
            if (string[i] == ')')
            {
                thisVarCheckingString --;
            }
        }
        return thisVarCheckingString;
    }
}

int answer(int thisVarCheckingString)
{
    if (thisVarCheckingString == 0)
    {
        printf("Yep");
    }
    else
    {
        printf("Nope");
    }
}
int main()
{
    char string[] = ")()()(";
    answer(check(string));
}
