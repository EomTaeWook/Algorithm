// 56DigitsProduct.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <vector>
int digitsProduct(int product)
{
	if (product == 0) return 10;
	else if (product >= 1 && product <= 9) return product;
	std::vector<int> output;
	int idx = 10;
	while (--idx >= 2)
	{
		if (product % idx == 0)
		{
			output.push_back(idx);
			product /= idx;
			if (product == 1)break;
			idx = 10;
		}

	}
	if (product >= 10) output.clear();
	if (output.size() == 0) return -1;
	int digit = 1;
	for (int i = product = 0; i < output.size(); i++, digit *= 10)
		product += output[i] * digit;
	return product;
}
int main()
{
	digitsProduct(12);
    return 0;
}

