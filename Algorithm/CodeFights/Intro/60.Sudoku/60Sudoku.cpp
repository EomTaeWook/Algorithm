// 60Sudoku.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<vector>
#include<set>
bool sudoku(std::vector<std::vector<int>> grid) {
	std::set<int> col;
	std::set<int> row;
	std::set<int> square;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int ii = 0; ii < grid[i].size(); ii++)
		{
			if (col.count(grid[i][ii]) > 0) return false;
			col.insert(grid[i][ii]);

			if (ii % 3 == 0 && i % 3 == 0)
			{
				for (int y = i; y < i + 3; y++)
				{
					for (int x = ii; x < ii + 3; x++)
					{
						if (square.count(grid[y][x]) > 0) return false;
						square.insert(grid[y][x]);
					}
				}
				square.clear();
			}
			if (i > 0)continue;
			if(row.count(grid[ii][i]) > 0) return false;
			row.insert(grid[ii][i]);
		}
		col.clear();
		row.clear();
		square.clear();
	}
	return true;
}

int main()
{		
	std::vector<std::vector<int>> v = {
		{ 1, 3, 2, 5, 4, 6, 9, 8, 7 },
		{ 4, 6, 5, 8, 7, 9, 3, 2, 1 },
		{ 7, 9, 8, 2, 1, 3, 6, 5, 4 },
		{ 9, 2, 1, 4, 3, 5, 8, 7, 6 },
		{ 3, 5, 4, 7, 6, 8, 2, 1, 9 },
		{ 6, 8, 7, 1, 9, 2, 5, 4, 3 },
		{ 5, 7, 6, 9, 8, 1, 4, 3, 2 },
		{ 2, 4, 3, 6, 5, 7, 1, 9, 8 },
		{ 8, 1, 9, 3, 2, 4, 7, 6, 5 } };
	sudoku(v);
    return 0;
}

