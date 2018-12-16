#include <iostream>
#include <string.h>
int input[101], N;
long long memo[101][21];
long long Solve(int idx, int sum)
{
	if (sum < 0 || sum > 20)
		return 0;
	if (sum == input[N-1] && idx == N - 1)
		return 1;
	if (idx >= N - 1)
		return 0;
	if (memo[idx][sum] != -1)
		return memo[idx][sum];
	return memo[idx][sum] = Solve(idx + 1, sum + input[idx]) + Solve(idx + 1, sum - input[idx]);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> input[i];
	memset(memo, -1, sizeof(memo));
	printf("%lld\n", Solve(1, input[0]));
	return 0;
}