#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::string input;
	std::cin >> input;
	int count[10] = { 0, };
	int max = 0;
	for (auto i = 0; i < input.size(); i++)
	{
		if (input[i] == '9' || input[i] == '6')
		{
			count[6]++;
			continue;
		}
		else
			count[input[i] - '0']++;
		if (max < count[input[i] - '0'])
			max = count[input[i] - '0'];
	}
	max = std::max(max, count[6] / 2 + count[6] % 2);
	printf("%d\n", max);
	return 0;
}