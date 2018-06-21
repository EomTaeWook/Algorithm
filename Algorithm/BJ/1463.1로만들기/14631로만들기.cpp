#include <iostream>
#include <algorithm>
#include <string.h>
int memo[1000001];
int input;
int Recursion(int val)
{
	if (val == 1) return 0;
	if (memo[val] != -1) return memo[val];
	int ans = memo[val] = input;
	if (val % 3 == 0)
		ans = std::min(ans, Recursion(val / 3) + 1);
	if (val % 2 == 0)
		ans = std::min(ans, Recursion(val / 2) + 1);
	ans = std::min(ans, Recursion(val - 1) + 1);
	if (memo[val] > ans)
		memo[val] = ans;
	return memo[val];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> input;
	memset(memo, -1, sizeof(memo));
	memo[2] = memo[3] = 1;
	printf("%d\n", Recursion(input));
	return 0;
}