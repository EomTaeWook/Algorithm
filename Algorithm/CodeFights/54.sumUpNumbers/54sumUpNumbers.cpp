// 54sumUpNumbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string>
#include<regex>
int sumUpNumbers(std::string inputString) {
	std::regex re("([0-9]+)");
	std::smatch m;
	int sum = 0;
	while (std::regex_search(inputString, m, re))
	{
		sum += std::atoi(m[0].str().c_str());
		inputString = m.suffix();
	}
	return sum;
}

int main()
{
	sumUpNumbers("2 apples, 12 oranges");
    return 0;
}

