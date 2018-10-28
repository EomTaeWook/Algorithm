#include <iostream>
#include <string.h>
#include <algorithm>
int arr[101];
int memo[101][10001];
int N, K;
int Solve(const int& idx, const int& k, const int& sel)
{
	if (k > K || idx > N)
		return 987654321;
	if (k == K)
		return 0;
	if (memo[idx][k] != -1)
		return memo[idx][k];
	memo[idx][k] = 987654321;
	memo[idx][k] = std::min(Solve(idx + 1, k, sel), Solve(idx, k + arr[idx], sel + 1) );
	return memo[idx][k];
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	::memset(memo, -1, sizeof(memo));
	auto ans = Solve(0, 0, 0);
	printf("%d\n", ans == 987654321 ? -1 : ans);


	return 0;
}