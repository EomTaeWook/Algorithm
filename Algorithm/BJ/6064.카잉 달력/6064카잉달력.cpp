// 6064카잉달력.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	int M = 10, N = 12, x = 3, y = 9;
	int i = x, count = x;
	while (t-- > 0)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		i = x % N, count = x;
		bool find = false;
		while (count <= M * N)
		{
			if (i == 0) i = N;
			if (i == y)
			{
				find = true;
				break;
			}
			count += M;
			i = count % N;
		}
		printf("%d\n", find ? count : -1);
	}
	return 0;
}