// 1890점프.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <string.h>
int maze[100][100];
long long visit[100][100];
int next_X[2] = {0,1};
int next_Y[2] = { 1,0 };
int size = 4;
long long DFS(int x, int y)
{
	if (x == size - 1 && y == size - 1) return 1;
	if(x < 0 || x > size-1 || 
		y < 0 || y > size -1)
		return 0;
	if (visit[y][x] != -1) 
		return visit[y][x];
	visit[y][x] = 0;
	for (int i = 0; i < 2; i++)
		visit[y][x] += DFS(x + maze[y][x] * next_X[i], y + maze[y][x] * next_Y[i]);
	return visit[y][x];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> size;
	for (int i = 0; i < size; i++)
		for (int ii = 0; ii < size; ii++)
			std::cin >> maze[i][ii];
	memset(visit, -1, sizeof(visit));
	std::cout << DFS(0, 0) <<std::endl;
    return 0;
}

