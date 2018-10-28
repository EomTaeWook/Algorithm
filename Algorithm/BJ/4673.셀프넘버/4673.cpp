#include<stdio.h>
int Solve(const int & num)
{
	if (num < 10) 
		return num;
	return Solve(num / 10) + num % 10;
}
int main()
{
	bool selfNum[10001] = {false, };		
	for (int i = 1; i < 10000; i++)
	{
		selfNum[i + Solve(i)] = true;
		if (!selfNum[i])
			printf("%d\n", i);
	}
	return 0;
}