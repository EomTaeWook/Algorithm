// 59SpiralNumbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <vector>
std::vector<std::vector<int>> spiralNumbers(int n) {
	std::vector<std::vector<int>> _list;
	for (int i = 0; i < n; i++)
		_list.push_back(std::vector<int>(n));
	int x = -1, y = 0, idx = 1;
	int jump = 1, max = n *n;
	while (idx <= max)
	{
		for (int i = 0; i < n; i++)
		{			
			x += jump;
			_list[y][x] = idx++;
		}
		for (int i = 0; i < n - 1; i++)
		{
			y += jump;
			_list[y][x] = idx++;
		}
		jump *= -1;
		n--;
	}
	return _list;
}

int main()
{
	spiralNumbers(5);
    return 0;
}

