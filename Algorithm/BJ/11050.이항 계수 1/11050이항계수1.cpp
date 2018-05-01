// 11050이항계수1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
int Factorial(int n)
{
	if (n <= 1) return 1;
	return n * Factorial(n - 1);
}
int main()
{
	int n = 5, k = 2;
	scanf("%d %d", &n, &k);
	printf("%d\n", Factorial(n) / (Factorial(k) * Factorial(n - k)));
	return 0;
}