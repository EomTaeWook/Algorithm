#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int tcase = 0, input = 0, v = 0;
	std::cin >> tcase;
	for(int i=0; i<tcase; i++)
	{
		int building = 0, rule = 0;
		std::cin >> building >> rule;
		int time[1001] = { 0, }, vertex[1001] = { 0, }, output[1001] = { 0, };
		for (int i = 0; i < building; i++)
			std::cin >> time[i + 1];
		std::vector<int> dist[1001];
		for (int i = 0; i < rule; i++)
		{
			std::cin >> input >> v;
			dist[input].push_back(v);
			vertex[v]++;
		}
		std::cin >> input;
		std::queue<int> q;
		for (int i = 1; i < building; i++)
		{
			if (vertex[i] == 0)
			{
				q.push(i);
				output[i] = time[i];
			}
		}
		while (!q.empty())
		{
			auto idx = q.front();
			q.pop();
			for (int i = 0; i < dist[idx].size(); i++)
			{
				auto next = dist[idx][i];
				output[next] = std::max(time[next] + output[idx], output[next]);
				if(--vertex[next] == 0)
					q.push(next);
			}
		}
		printf("%d\n", output[input]);
	}
	return 0;
}