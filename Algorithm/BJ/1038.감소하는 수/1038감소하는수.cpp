// 1038감소하는수.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <string>
#include <set>
int input;
int count = 9;
std::set<std::string> _set;
std::string result = "-1";
void Recursion(int digit, int idx, std::string value)
{
	if (digit <= 0) return;
	for (int i = 0; i <idx; i++)
	{
		value.push_back(i + '0');
		Recursion(digit - 1, i, value);
		if (result != "-1") return;
		_set.insert(value);
		if (_set.size() + count == input)
		{
			result = value;
			return;
		}
		value.pop_back();
	}
}
int main()
{
	scanf("%d", &input);
	_set.clear();
	if (input < 10)
		printf("%d", input);
	else
	{
		count = 9;
		for (int digit = 1; digit < 10; digit++)
		{
			for (int i = 1; i < 10; i++)
				Recursion(digit, i, std::to_string(i));
		}
		printf("%s\n", result.c_str());
	}
	return 0;
}
