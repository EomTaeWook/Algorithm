#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
int main()
{
	int ranks[501] = { 0, };
	int vertex[501] = { 0, };
	bool graph[501][501] = {false, };
	std::ios::ios_base::sync_with_stdio(false);
	int t = 0;
	std::cin >> t;
	while (t-- > 0)
	{
		memset(graph, 0, sizeof(graph));
		int N, M, input1, input2;
		std::cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			std::cin >> ranks[i];
			vertex[ranks[i]] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			for (int ii = i + 1; ii < N; ii++)
			{
				graph[ranks[i]][ranks[ii]] = true;
				vertex[ranks[ii]]++;
			}
		}
		std::cin >> M;
		for (int i = 0; i < M; i++)
		{
			std::cin >> input1 >> input2;
			if (graph[input1][input2])
			{
				graph[input1][input2] = false;
				graph[input2][input1] = true;
				vertex[input2]--;
				vertex[input1]++;
			}
			else
			{
				graph[input1][input2] = true;
				graph[input2][input1] = false;
				vertex[input2]++;
				vertex[input1]--;
			}
		}
		std::queue<int> q;
		std::vector<int> output;
		for (int i = 1; i <= N; i++)
		{
			if (vertex[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			if (q.size() > 1)
				break;
			auto idx = q.front(); q.pop();
			output.push_back(idx);
			for(int ii = 1; ii<= N; ii++)
			{
				if (graph[idx][ii])
				{
					vertex[ii]--;
					if (vertex[ii] == 0)
						q.push(ii);
				}
			}
		}
		if (output.size() != N)
			printf("IMPOSSIBLE");
		else if (q.size() > 1)
			printf("?");
		else
		{
			for(auto i : output)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}