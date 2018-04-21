// 2606바이러스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
std::vector<int> list[101];
int visit[101];
int main()
{
	int size = 0, contact_size = 0;
	int index = 0, contact;
	scanf("%d", &size);
	scanf("%d", &contact_size);
	for (int i = 0; i < contact_size; i++)
	{
		scanf("%d %d", &index, &contact);
		list[index].push_back(contact);
		list[contact].push_back(index);
	}
	memset(visit, -1, sizeof(visit));
	std::queue<std::vector<int>> q;
	q.push(list[1]);
	visit[1] = 1;
	int count = 0;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();
		for (int i = 0; i < node.size(); i++)
		{
			if (visit[node[i]] == -1)
			{
				visit[node[i]] = 1;
				q.push(list[node[i]]);
				count++;
			}
		}
	}
	printf("%d\n", count);
    return 0;
}

