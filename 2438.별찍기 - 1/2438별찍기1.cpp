// 2438별찍기1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
int main()
{
	int input = 5;
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		for (int ii = 0; ii < i + 1; ii++)
		{
			printf("*");
		}
		printf("\n");
	}
    return 0;
}

