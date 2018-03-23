// 13241최소공배수.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include<algorithm>
int main()
{
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	if (a < b)
		std::swap(a, b);
	int mod = a % b;
	int gcd = b;
	while (mod != 0)
	{
		gcd = gcd % mod;
		std::swap(gcd, mod);
	}
	printf("%lld\n", a * b / gcd);
    return 0;
}

