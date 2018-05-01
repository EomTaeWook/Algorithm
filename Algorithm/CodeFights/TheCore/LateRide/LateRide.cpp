// LateRide.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int lateRide(int n) {
	return n % 60 % 10 + n % 60 / 10 + n / 60 % 10 + n / 60 / 10 % 10;
}

int main()
{
	lateRide(808);
    return 0;
}

