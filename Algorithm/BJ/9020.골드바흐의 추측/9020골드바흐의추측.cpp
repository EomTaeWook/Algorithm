// 9020골드바흐의추측.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<string.h>
#include<stdio.h>
int primeNumber[10001];
int main()
{
	memset(primeNumber, 0, sizeof(primeNumber));
	for (int i = 2; i <= 10000; i++)
	{
		if (primeNumber[i] == -1) continue;
		for (int ii = i+1; ii < 10000; ii++)
		{
			if (ii % i == 0)
				primeNumber[ii] = -1;
		}
	}
	int t;
	scanf("%d", &t);
	int input;
	bool isFind = false;
	while (t-- > 0)
	{
		scanf("%d", &input);
		isFind = false;
		for (int i = input/2; i >= 1; i--)
		{
			if (primeNumber[i] == -1) continue;
			for (int ii = input / 2; ii <= input; ii++)
			{
				if (primeNumber[ii] == -1) continue;
				if (i + ii > input) break;
				if (i + ii == input)
				{
					printf("%d %d\n", i, ii);
					isFind = true;
					break;
				}
			}
			if (isFind)break;
		}
	}
    return 0;
}

