#include <iostream>

int input[1000000] = { 1, 2, 3, 1, 2 };
int sum[1000000];
int max = 5, m = 3;

int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	
	sum[0] = input[0];
	for (int i = 1; i < max; i++)
		sum[i] = input[i] + sum[i - 1];
	int count = 0;
	for (int i = 0; i < max; i++)
	{
		for (int ii = i; ii < max; ii++)
		{
			if ((sum[ii] - sum[i]) % 3 == 0)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}