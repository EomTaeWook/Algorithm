// 7569토마토.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<queue>

int mx[6] = { 0, 0, -1, 1, 0 , 0 };//상하좌우
int my[6] = { -1, 1, 0, 0, 0 , 0 };//상하좌우
int mz[6] = { 0, 0, 0, 0, -1 , 1 };//상하좌우
int tomato[101][101][101];
int max_x = 6, max_y = 4, max_z = 1;
struct Tomato
{
	int x;
	int y;
	int z;
	Tomato(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int main()
{
	std::queue<Tomato> q;
	scanf("%d %d %d", &max_x, &max_y, &max_z);
	for (int z = 0; z < max_z; z++)
	{
		for (int y = 0; y < max_y; y++)
		{
			for (int x = 0; x < max_x; x++)
			{
				scanf("%d", &tomato[z][y][x]);
				if (tomato[z][y][x] == 1)
					q.push(Tomato(x, y, z));
			}
		}
	}
	
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (t.x + mx[i] >= 0 && t.x + mx[i] < max_x 
				&& t.y + my[i] >= 0 && t.y + my[i] < max_y 
				&& t.z + mz[i] >= 0 && t.z + mz[i] < max_z
				&& tomato[t.z +mz[i]][t.y + my[i]][t.x + mx[i]] == 0)
			{
				tomato[t.z + mz[i]][t.y + my[i]][t.x + mx[i]] = tomato[t.z][t.y][t.x] + 1;
				q.push(Tomato(t.x + mx[i], t.y + my[i], t.z + mz[i]));
			}
		}
	}
	int max = 0;
	int forceExit = false;
	for (int z = 0; z < max_z; z++)
	{
		for (int y = 0; y < max_y; y++)
		{
			for (int x = 0; x < max_x; x++)
			{
				if (max < tomato[z][y][x]) max = tomato[z][y][x] - 1;
				if (tomato[z][y][x] == 0)
				{
					max = -1;
					forceExit = true;
					break;
				}
			}
			if (forceExit)break;
		}
		if (forceExit)break;
	}
	
	printf("%d\n", max);
	return 0;
}