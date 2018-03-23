// 1057토너먼트.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
int main()
{
	int count, k, i, round = 1;
	scanf("%d %d %d", &count, &k, &i);
	while (count > 0)
	{
		if ((k & 1) == 0 && k - 1 == i)
			break;
		else if ((k & 1) == 1 && k + 1 == i)
			break;
		if ((i & 1) == 1 && i + 1 == k)
			break;
		else if ((i & 1) == 0 && i - 1 == k)
			break;
		count = count / 2 + (count % 2);
		k = k / 2 + (k % 2);
		i = i / 2 + (i % 2);
		round++;
	}
	printf("%d\n", round);
 	return 0;
}