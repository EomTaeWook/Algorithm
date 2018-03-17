// 1912연속합.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<algorithm>
#include<string.h>
int input[100001] = {10, -4, 3, 1, 5, 6, -35, 12, 21, -1};
int memo[100002];
int size = 11;
int GetSolve(int index)
{
	if (index >= size) return -987654321;
	if (memo[index] != -987654321) return memo[index];
	memo[index] = std::max(GetSolve(index + 1) + input[index], input[index]);
	return memo[index];
}
int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &input[i]);
		memo[i] = -987654321;
	}
	GetSolve(0);
	int max = -987654321;
	for (int i = 0; i < size; i++)
	{
		if (max < memo[i]) max = memo[i];
	}
	printf("%d", max);
    return 0;
}