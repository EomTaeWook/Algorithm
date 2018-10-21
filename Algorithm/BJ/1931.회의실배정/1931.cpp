#include <iostream>
#include <algorithm>
#include <vector>
std::pair<long long, long long> input[100001];
long long time[100001];
bool Compare(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right)
{
	if (left.first == right.first)
		return left.second < right.second;
	else
		return left.first < right.first;
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::pair<long long, long long> p;
		std::cin >> p.first >> p.second;
		input[i] = p;
	}
	std::sort(input, input + N, Compare);
	auto count = 1;
	auto sel = input[0];
	for (int i = 1; i < N; i++)
	{
		if (input[i].first >= sel.second)
		{
			count++;
			sel = input[i];
		}
		else if(input[i].second <sel.second)
			sel = input[i];
	}
	printf("%d\n", count);
	return 0;
}