// 6CircleOfNumbers.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int circleOfNumbers(int n, int firstNumber) {
	return (firstNumber % n + n / 2) % n;
}

int main()
{
	circleOfNumbers(10, 2);
    return 0;
}

