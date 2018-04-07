// 1011FlymetotheAlphaCentauri.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<cmath>
#include <stdio.h>
int main()
{
	long long t = 1,s, f, dis = 13;
	scanf("%lld", &t);
	while (t-- > 0)
	{
		scanf("%lld %lld", &s, &f);
		dis = f - s;
		if (dis == 1 || dis == 2)
		{
			printf("%lld\n", dis);
			continue;
		}
		auto sqrt = (long long)std::ceil(std::sqrt(dis));
		auto max = (long long)std::pow(sqrt, 2);
		if (max - sqrt >= dis)
			printf("%lld\n", sqrt * 2 - 2);
		else
			printf("%lld\n", sqrt * 2 - 1);
	}
    return 0;
}

