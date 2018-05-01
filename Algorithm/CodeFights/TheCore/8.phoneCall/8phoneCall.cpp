// 8phoneCall.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int phoneCall(int min1, int min2_10, int min11, int s) {
	s -= min1;
	if (s == 0) return 1;
	else if (s < 0) return 0;
	int time = 1;
	for (int i = 1; i < 10; i++)
	{
		s -= min2_10;
		if (s <= 0) return time;
		time++;
	}
	time += s / min11;
	return time;
}
int main()
{
	phoneCall(1, 2, 1, 6);
    return 0;
}

