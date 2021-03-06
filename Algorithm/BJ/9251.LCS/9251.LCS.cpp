// 9251.LCS.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include<string>
#include<algorithm>
int memo[1001][1001] = { 0 };
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::string input1, input2;;
	std::cin >> input1 >> input2;
	input1 = input1.insert(0, "0");
	input2 = input2.insert(0, "0");
	for (auto i = 1; i < input1.size(); i++)
	{
		for (auto ii = 1; ii < input2.size(); ii++)
		{
			if (input1[i] == input2[ii])
				memo[i][ii] = memo[i - 1][ii - 1] + 1;
			else
				memo[i][ii] = std::max(memo[i][ii - 1], memo[i - 1][ii]);
		}
	}
	printf("%d\n", memo[input1.size() - 1][input2.size() - 1]);
    return 0;
}