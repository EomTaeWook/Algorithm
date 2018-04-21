// 9037TheCandyWar.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
#include<vector>
int main() {
	int t = 0;
	scanf("%d", &t);
	std::vector<int> v;
	int size = 0, input, cycle;
	std::vector<int> temp;
	bool equal = true;
	for (int i = 0; i < t; i++)
	{
		v.clear();
		temp.clear();
		scanf("%d", &size);
		for (int ii = 0; ii < size; ii++)
		{
			scanf("%d", &input);
			if ((input & 1) == 1) input++;
			v.push_back(input);
		}
		temp.assign(v.size(), 0);
		cycle = 0;
		while (true)
		{
			equal = true;
			for (int i = 0; i < v.size(); i++)
			{
				temp[i] = v[i] /= 2;
				if (i == 0 || !equal) continue;
				if (v[i] != v[i - 1])
					equal = false;
			}
			if (equal) break;
			for (int i = 1; i < v.size(); i++)
			{
				v[i] += temp[i - 1];
				if ((v[i] & 1) == 1) v[i]++;
			}
			v[0] += temp[temp.size() - 1];
			if ((v[0] & 1) == 1) v[0]++;
			cycle++;
		}
		printf("%d\n", cycle);
	}
	return 0;
}