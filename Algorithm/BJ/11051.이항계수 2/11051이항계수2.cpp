// 11051이항계수2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
unsigned int memo[1001][1001];
unsigned int Combination(int n, int k)
{
	if (n == k) return 1;
	if (k <= 1) return n;
	if (memo[n][k] != 0) return memo[n][k];
	return memo[n][k] = (Combination(n - 1, k - 1) + Combination(n - 1, k)) % 10007;
}
int main()
{
	int n = 1000, k = 2;
	memset(&memo, 0, sizeof(memo));
	scanf("%d %d", &n, &k);
	printf("%u\n", Combination(n, k));
	return 0;
}
