// 1932숫자삼각형.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//



//
//		  7
//		3   8 
//	  8,  1,  0
//	2,  7,  4,  4
//4,  5,  2,  6,  5

//        0
//      1   2 
//	  3   4   5
//	6   7   8   9
//10  11  12  13  14

#include "stdafx.h"
#include<string.h>
#include<stdio.h>
#include<vector>
int maxDepth = 5;
std::vector<int> memo;
std::vector<int> list;
int Solve(int depth, int sum, int idx)
{
	if (depth > maxDepth) return sum;
	if (idx + depth >= list.size()) return sum;
	if (idx + depth + 1 >= list.size()) return sum;
	if (memo[idx] != -1) 
		return memo[idx];
	int left = Solve(depth + 1, list[idx + depth], idx + depth) + sum;
	int right = Solve(depth + 1, list[idx + depth + 1], idx + depth + 1) + sum;
	return memo[idx] = left > right ? left : right;
}
int main()
{
	scanf("%d", &maxDepth);
	int input;
	for (int i = 0; i < maxDepth; i++)
	{
		for (int ii = 0; ii < i + 1; ii++)
		{
			scanf("%d", &input);
			list.push_back(input);
			memo.push_back(-1);
		}
	}
	printf("%d\n", Solve(1, list[0], 0));
	return 0;
}

