// 2156포도주시식.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<algorithm>
int list[10000] = { 10, 22, 1 ,10,  };
int max = 4;
int memo[10001][3];
int Solve(int idx, int select)
{
	if (idx >= max) return 0;
	if (memo[idx][select] != -1) return memo[idx][select];
	int temp = Solve(idx + 1, 0);
	if (select < 2)
		temp = std::max(temp, Solve(idx + 1, select + 1) + list[idx]);
	else
		temp = std::max(temp, Solve(idx + 2, 0));
	return memo[idx][select] = temp;
}
int main()
{
	scanf("%d", &max);
	for (int i = 0; i < max; i++)
		scanf("%d", &list[i]);
	memset(memo, -1, sizeof(memo));
	printf("%d\n", Solve(0, 0));
    return 0;
}

