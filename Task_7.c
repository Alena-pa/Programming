#include <stdio.h>

int check(char *string, char *miniString)
{
	int count = 0;
	for (int i = 0; i < (strlen(string) - strlen(miniString) + 1); i++)
	{
		int a = 0;
		int index = i;
		for (int j = 0; j < strlen(miniString); j ++)
		{
			if (string[index + j] == miniString[j])
			{
				a++;
			}
		}
		if (a == strlen(miniString))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	const char string[] = "inthisstringtherearealotofwordswordswords";
	const char miniString[] = "word";
	int answer = check(string, miniString);
	printf("%d", answer);
}
