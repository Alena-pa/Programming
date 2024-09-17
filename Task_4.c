#include <stdio.h>

int counter()
{
	int list[29] = { 0 };
	for (int i = 0; i < 1000; i++)
	{
		int index = i;
		int summ = 0;
		for (int j = 0; index > 0; j++)
		{
			summ += index % 10;
			index /= 10;
		}
		list[summ] = list[summ] + 1;
	}
	int answer = 0;
	for (int i = 0; i < 29; i++)
	{
		answer += list[i] * list[i];
	}
	return answer;
}

int main()
{
	int answer = counter();
	printf("%d", answer);
}
