#include <iostream>
#include <algorithm>
int input[1001];
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int N, sum = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> input[i];
	std::sort(input, input + N);
	for (int i = 1; i < N; i++)
		input[i] += input[i - 1];
	for (int i = 0; i < N; i++)
		sum += input[i];
	printf("%d", sum);
	return 0;
}