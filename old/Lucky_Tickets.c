#include <stdio.h>

int counter()
{
	int arrayOfIntegers[28] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int q = 0; q < 10; q++)
			{
				int sumOfNumbers = i + j + q;
				arrayOfIntegers[sumOfNumbers]++;
			}

		}
	}
	int answer = 0;
	for (int i = 0; i < 28; i++)
	{
		answer += arrayOfIntegers[i] * arrayOfIntegers[i];
	}
	return answer;
}

int main()
{
	int answer = counter();
	printf("%d", answer);
}
