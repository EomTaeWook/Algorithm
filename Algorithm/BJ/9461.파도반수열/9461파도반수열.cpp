// 9461파도반수열.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
long long memo[101];
int main()
{
	memset(memo, -1, sizeof(memo));
	long long temp[8] = {1, 1, 1, 2, 2, 3, 4, 5 };
	memcpy(memo, temp, sizeof(temp));
	for (int i = 8; i < 100; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 5];
	}
	int t = 1;
	scanf("%d", &t);
	int input;
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &input);
		printf("%lld\n", memo[input - 1]);
	}
    return 0;
}