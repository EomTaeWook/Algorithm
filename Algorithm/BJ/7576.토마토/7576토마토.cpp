// 7576토마토.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<queue>

int mx[4] = { 0, 0, -1, 1 };//상하좌우
int my[4] = { -1, 1, 0, 0 };//상하좌우
int tomato[1001][1001];
int max_x = 6, max_y = 4;
struct Tomato
{
	int x;
	int y;
	Tomato(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

int main()
{
	std::queue<Tomato> q;
	scanf("%d %d", &max_x, &max_y);
	for (int y = 0; y < max_y; y++)
	{
		for (int x = 0; x < max_x; x++)
		{
			scanf("%d", &tomato[y][x]);
			if (tomato[y][x] == 1)
				q.push(Tomato(x, y));
		}
	}
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (t.x + mx[i] >= 0 && t.x + mx[i] < max_x && t.y + my[i] >= 0 && t.y + my[i] < max_y && tomato[t.y + my[i]][t.x + mx[i]] == 0)
			{
				tomato[t.y + my[i]][t.x + mx[i]] = tomato[t.y][t.x] + 1;
				q.push(Tomato(t.x + mx[i], t.y + my[i]));
			}
		}
	}
	int max = 0;
	int forceExit = false;
	for (int y = 0; y < max_y; y++)
	{
		for (int x = 0; x < max_x; x++)
		{
			if (max < tomato[y][x]) max = tomato[y][x] - 1;
			if (tomato[y][x] == 0)
			{
				max = -1;
				forceExit = true;
				break;
			}
		}
		if (forceExit)break;
	}
	printf("%d\n", max);
    return 0;
}

