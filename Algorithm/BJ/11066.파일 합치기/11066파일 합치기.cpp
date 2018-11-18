#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
int list[501] = {40, 30, 30, 50};
int memo[501][501];
int Cost(const int& start, const int& end)
{
	if (start == end)
		return 0;

	if (start + 1 == end)
		return list[start] + list[end];

	if (memo[start][end] != -1)
		return memo[start][end];

	memo[start][end] = 987654321;
	for (int i = start; i < end; i++)
	{

	}

	return memo[start][end];
}
int main()
{
	int t=0, tc = 1, K = 4;
	//std::cin >> tc;
	while (t++ < tc)
	{
		//40 30 30 50
		//std::cin >> size;
		/*for (int i = 0; i < size; i++)
			std::cin >> list[i];*/
		memset(memo, -1, sizeof(memo));

		printf("%d\n", Cost(0, K));
	}
	return 0;
}