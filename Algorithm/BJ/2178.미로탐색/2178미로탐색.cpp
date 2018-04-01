// 2178미로탐색.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <queue>
#include <string.h>
int maze[101][101];
int visit[101][101];
int max_x, max_y;
int move_x[] = { 0,0,-1,1 };
int move_y[] = { 1,-1,0,0 };
struct Point
{
	int X, Y;
public:
	Point(int x, int y)
	{
		this->X = x;
		this->Y = y;
	}
};
int main()
{
	char input[101];
	scanf("%d %d", &max_y, &max_x);
	for (int i = 0; i < max_y; i++)
	{
		scanf("%s", &input);
		for (int ii = 0; ii < strlen(input); ii++)
		{
			maze[i][ii] = input[ii] - '0';
		}
	}
	memset(visit, 0, sizeof(visit));
	std::queue<Point> q;
	q.push(Point(0, 0));
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		if (p.X == max_x - 1 && p.Y == max_y - 1) break;
		for (int i = 0; i < 4; i++)
		{
			int n_x = move_x[i] + p.X, n_y = move_y[i] + p.Y;
			if (n_x >= 0 && n_x < max_x 
				&& n_y >= 0 && n_y < max_y
				&& visit[n_y][n_x] == 0
				&& maze[n_y][n_x] == 1)
			{
				q.push(Point(n_x, n_y));
				visit[n_y][n_x] = visit[p.Y][p.X] + 1;
			}
		}
	}
	printf("%d\n", visit[max_y - 1][max_x - 1] + 1);
    return 0;
}