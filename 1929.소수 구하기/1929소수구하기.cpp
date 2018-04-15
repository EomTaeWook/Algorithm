// 1929소수구하기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#include<stdio.h>
#include<string.h>
int prime[1000001];
int main() {
	memset(&prime, 0, sizeof(prime));
	prime[1] = -1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (prime[i] == -1) continue;;
		for (int ii = i + i; ii <= 1000000; ii += i)
			prime[ii] = -1;
	}
	int begin, end;
	scanf("%d %d", &begin, &end);
	for (int i = begin; i <= end; i++)
	{
		if (prime[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}