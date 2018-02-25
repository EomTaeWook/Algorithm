// 53vaildtime.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string>
bool validTime(std::string time) {
	int index = time.find(":");
	int hour = std::stoi(time.substr(0, index));
	int min = std::stoi(time.substr(index + 1, 2));
	if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59)
		return true;
	else
		return false;
}
int main()
{
	validTime("24:00");

	
    return 0;
}

