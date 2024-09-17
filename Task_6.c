#include <stdio.h>

int check(int number)
{
	int count = 0;
	for (int i = 2; i < number; i ++)
	{
		if (number % i == 0)
		{
			count++;
		}
	}
	if (count == 0)
	{
		return count;
	}
}

void answer(number)
{
	for (int i = 1; i <= number; i++)
	{
		if (check(i) == 0)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{
	answer(64);
}
