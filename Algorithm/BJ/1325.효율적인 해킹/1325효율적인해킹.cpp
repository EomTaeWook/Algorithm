// 1325효율적인해킹.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include <vector>
#include <queue>
#include <string.h>
int visit[10001] = { 0 };
bool check[10001] = { false, };
std::vector<int> list[10001];
int main()
{
	int N, M, a, b;
	std::vector<int> ans;
	std::queue<int> q;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		list[b].push_back(a);
	}
	ans.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		visit[i]++;
		memset(check, false, sizeof(check));
		q.push(i);
		while (!q.empty())
		{
			auto n = q.front();
			q.pop();
			visit[i]++;
			check[i] = true;
			for (int ii = 0; ii < list[n].size(); ii++)
			{
				if (check[list[n][ii]]) continue;
				check[list[n][ii]] = true;
				q.push(list[n][ii]);
			}
		}
		if (visit[ans.back()] < visit[i])
		{
			ans.clear();
			ans.push_back(i);
		}
		else if (visit[ans.back()] == visit[i])
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
    return 0;
}