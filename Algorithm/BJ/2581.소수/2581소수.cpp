// 2581소수.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
int prime[10001];
int main() {
	memset(&prime, 0, sizeof(prime));
	prime[1] = -1;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] == -1) continue;;
		for (int ii = i + i; ii <= 10000; ii += i)
			prime[ii] = -1;
	}
	int begin, end;
	scanf("%d %d", &begin, &end);
	int sum = 0;
	int min = -1;
	for (int i = begin; i <= end; i++)
	{
		if (prime[i] == 0)
		{
			sum += i;
			if (min == -1 || min > i)
				min = i;
		}

	}
	printf("%d\n", min != -1 ? sum : -1);
	if (min != -1) printf("%d\n", min);
	return 0;
}