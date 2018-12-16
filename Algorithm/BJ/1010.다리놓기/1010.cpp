#include<iostream>
#include <string.h>
int memo[31][31];
long Solve(const int& n, const int& r)
{
	if (n == r || r == 0)
		return 1;
	if (memo[n][r] != -1)
		return memo[n][r];
	return memo[n][r] = Solve(n - 1, r - 1) + Solve(n - 1, r);
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int T, N, M;
	std::cin >> T;
	while (T-- > 0)
	{
		std::cin >> N >> M;
		memset(memo, -1, sizeof(memo));
		printf("%ld\n", Solve(M, N));
	}
	return 0;
}