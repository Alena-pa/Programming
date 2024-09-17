include <stdio.h>

int counter()
{
	int list[29] = { 0 };
	for (int i = 0; i < 1000; i++)
	{
		int index = i;
		int summ = 0;
		if (i > 99)
		{
			for (int j = 0; j < 3; j++)
			{
				summ += index % 10;
				index /= 10;
			}
		}
		else 
		{
			summ += i;

		}
		list[summ - 1] = list[summ - 1] + 1;
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
