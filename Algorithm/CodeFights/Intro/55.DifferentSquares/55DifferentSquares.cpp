// 55DifferentSquares.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<vector>
#include<set>
int differentSquares(std::vector<std::vector<int>> matrix) {
	std::set<std::vector<int> > s;
	for (int i = 1; i<matrix.size(); i++)
		for (int j = 1; j<matrix[i].size(); j++)
			s.insert({ matrix[i - 1][j - 1],matrix[i - 1][j],matrix[i][j - 1],matrix[i][j] });
	return s.size();
}
int main()
{
	std::vector<std::vector<int>> matrix =
	{ {1, 2, 1 },
	{ 2, 2, 2 },
	{ 2, 2, 2 },
	{ 1, 2, 3 },
	{ 2, 2, 1 } };
	differentSquares(matrix);
    return 0;
}

