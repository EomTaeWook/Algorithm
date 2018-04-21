// 58MessageFromBinaryCode.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include<string>
std::string messageFromBinaryCode(std::string code) {
	std::string output;
	for (int i = 0; i < code.size(); i += 8)
	{
		int dec = 0;
		for (int ii = i; ii < i + 8; ii++)
			dec |= (code[ii] - '0' << i + 7 - ii);
		output.push_back((char)(dec));
	}
	return output;
}

int main()
{
	messageFromBinaryCode("010010000110010101101100011011000110111100100001");
    return 0;
}

