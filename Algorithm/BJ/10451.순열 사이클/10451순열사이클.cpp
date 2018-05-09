// 10451순열사이클.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <queue>
#include <stdio.h>
#include <string.h>

int input[1001];
bool visit[1001];
int main()
{
	int t, size, count, n;
	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &size);
		for (int i = 1; i <= size; i++)
			scanf("%d", &input[i]);
		std::queue<int> q;
		count = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= size; i++)
		{
			q.push(input[i]);
			visit[i] = true;
			n = 0;
			while (!q.empty())
			{
				n = q.front();
				q.pop();
				if (!visit[n])
				{
					visit[n] = true;
					q.push(input[n]);
				}
			}
			if (n == i)
				count++;
		}
		printf("%d\n", count);
	}
    return 0;
}