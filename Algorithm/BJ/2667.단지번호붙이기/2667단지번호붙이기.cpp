// 2667단지번호붙이기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
int mv_x[4] = { 0,0,1,-1 };
int mv_y[4] = { -1,1,0,0 };
int visit[26][26];
int size;
std::vector<std::string> apt;
int DFS(int x, int y, int count)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + mv_x[i];
		int ny = y + mv_y[i];
		if (nx >= 0 && nx < size
			&& ny >= 0 && ny < size
			&& apt[ny][nx] == '1')
		{
			if (visit[ny][nx] !=1)
			{
				visit[ny][nx] = 1;
				count = DFS(nx, ny, count+1);
			}
		}
	}
	return count;
}
int main()
{
	char input[26];
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%s", &input);
		apt.push_back(input);
	}
	std::vector<int> house;
	memset(visit, 0, sizeof(visit));
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (visit[y][x] != 1 && apt[y][x] == '1')
			{
				visit[y][x] = 1;
				house.push_back(DFS(x, y, 0) + 1);
			}
		}
	}
	printf("%d\n", house.size());
	std::sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++)
		printf("%d\n", house[i]);
    return 0;
}

