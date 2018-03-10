// 1520내리막길.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include <string.h>
#define MAX 500
int mx[4] = { 0, 0, -1, 1 };//상하좌우
int my[4] = { -1, 1, 0, 0 };//상하좌우
int memo[MAX + 1][MAX + 1];
int maze[MAX][MAX];
int max_x = 5;
int max_y = 4;

bool Next(int x, int y, int idx)
{
	if (x + mx[idx] >= 0 && x + mx[idx] < max_x && y + my[idx] >= 0 && y + my[idx] < max_y)
		return true;
	else 
		return false;
}
int DFS(int x, int y)
{
	if (x == max_x - 1 && y == max_y - 1) return 1;
	if (x < 0 || x >= max_x || y < 0 || y >= max_y) return 0;
	if (memo[y][x] != -1) 
		return memo[y][x];

	memo[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Next(x, y, i) && maze[y][x] > maze[y + my[i]][x + mx[i]])
		{
			memo[y][x] += DFS(x + mx[i], y + my[i]);
		}
	}
	return memo[y][x];
}
int main()
{
	scanf("%d %d", &max_y, &max_x);
	for (int y = 0; y < max_y; y++)
	{
		for (int x = 0; x < max_x; x++)
		{
			scanf("%d", &maze[y][x]);
		}
	}
	memset(&memo, -1, sizeof(memo));
	printf("%d\n", DFS(0, 0));
    return 0;
}

