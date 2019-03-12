#include<iostream>
#include<vector>
#include<queue>

std::vector<int> input[32001];
int vertext[32001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	int N, M, in1, in2;

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> in1 >> in2;
		vertext[in2]++;
		input[in1].push_back(in2);
	}
	std::priority_queue<int> q;
	for (int i = 1; i <= N; ++i)
	{
		if (vertext[i] == 0)
			q.push(-i);
	}
	while (!q.empty())
	{
		auto idx = -q.top();
		q.pop();
		printf("%d ", idx);
		for (int i = 0; i < input[idx].size(); ++i)
		{
			vertext[input[idx][i]]--;
			if (vertext[input[idx][i]] == 0)
				q.push(-input[idx][i]);
		}
	}
	printf("\n");
	return 0;
}