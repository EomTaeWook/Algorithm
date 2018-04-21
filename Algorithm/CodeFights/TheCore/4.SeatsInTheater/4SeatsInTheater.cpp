// 4SeatsInTheater.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int seatsInTheater(int nCols, int nRows, int col, int row) {
	return (nCols - col + 1) * (nRows - row);
}

int main()
{
    return 0;
}

