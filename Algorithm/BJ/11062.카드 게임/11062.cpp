#include <iostream>
#include <algorithm>
#include <string.h>

int cards[1001] = { 1,2,5,2 };
int memo[2][1001][1001];
int sel(const int& left, const int& right, const bool& turn)
{
	if (left >= right)
		if (turn)
			return cards[left];
		else
			return 0;
	if (memo[turn][left][right] != -1)
		return memo[turn][left][right];

	if(turn)
		memo[turn][left][right] = std::max(sel(left + 1, right, !turn) + cards[left], sel(left, right - 1, !turn) + cards[right]);
	else
		memo[turn][left][right] = std::min(sel(left + 1, right, !turn), sel(left, right - 1, !turn));
	return memo[turn][left][right];
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int t = 1, N = 4;
	std::cin >> t;
	while (t-- > 0)
	{
		std::cin >> N;
		for (int i = 0; i < N; i++)
			std::cin >> cards[i];
		memset(memo, -1, sizeof(memo));
		printf("%d\n", sel(0, N - 1, 1));
	}
	return 0;
}