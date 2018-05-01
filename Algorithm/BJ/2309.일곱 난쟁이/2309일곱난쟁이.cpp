// 2309일곱난쟁이.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <vector>
#include <stdio.h>
#include <algorithm>
bool Recursion(int idx, std::vector<int>& input, std::vector<int>& output, int sum)
{
	if (sum == 100 && output.size() == 7)
		return true;
	if(idx >= input.size()) 
		return false;
	if (sum > 100)
		return false;
	if (Recursion(idx + 1, input, output, sum))
		return true;
	output.push_back(input[idx]);
	if (Recursion(idx + 1, input, output, sum + input[idx]))
		return true;
	output.pop_back();
	return false;
}
int main()
{
	int input;
	std::vector<int> v;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input);
		v.push_back(input);
	}
	std::sort(v.begin(), v.end());
	std::vector<int> output;
	for (int i = 0; i < v.size(); i++)
	{
		if (Recursion(i, v, output, 0))
			break;
	}
	for (int i = 0; i < output.size(); i++)
		printf("%d\n", output[i]);
    return 0;
}