// 1934최소공배수.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <algorithm>
#include <stdio.h>
int main()
{
	int t, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &a, &b);
		if (a < b)
			std::swap(a, b);
		int mod = a % b;
		int gcd = b;
		while (mod != 0)
		{
			gcd = gcd % mod;
			std::swap(gcd, mod);
		}
		printf("%d\n", a * b / gcd);
	}
    return 0;
}

