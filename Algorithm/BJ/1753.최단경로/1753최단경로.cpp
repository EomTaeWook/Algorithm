//#include <vector>
//#include <queue>
//#include <functional>
//#include <iostream>
////priority_queue 112ms
//struct Node
//{
//	int target;
//	int weight;
//};
//std::vector<Node> list[20001];
//int distance[20001];
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	int max, count, start, idx;
//	std::cin >> max >> count >> start;
//	for (int i = 0; i < count; i++)
//	{
//		Node n;
//		std::cin >> idx >> n.target >> n.weight;
//		list[idx].push_back(n);
//	}
//	for (int i = 1; i <= max; i++)
//		distance[i] = 987654321;
//	for (int i = 1; i <= max; i++)
//		distance[i] = 987654321;
//	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
//	q.push(std::make_pair(0, start));
//	distance[start] = 0;
//	while (!q.empty())
//	{
//		auto weight = q.top().first;
//		auto target = q.top().second;
//		q.pop();
//		if (distance[target] < weight) 
//			continue;
//		for (unsigned int i = 0; i < list[target].size(); i++)
//		{
//			auto nextWeight = list[target][i].weight + weight;
//			if (distance[list[target][i].target] > nextWeight)
//			{
//				distance[list[target][i].target] = nextWeight;
//				q.push(std::make_pair(nextWeight, list[target][i].target));
//			}
//		}
//	}
//	for (int i = 1; i <= max; i++)
//	{
//		if (distance[i] == 987654321)
//			printf("INF\n");
//		else
//			printf("%d\n", distance[i]);
//	}
//	return 0;
//}

//Normal Queue 144ms
#include <vector>
#include <queue>
#include <iostream>
struct Node
{
	int target;
	int weight;
};
std::vector<Node> list[20001];
int distance[20001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	int max, count, start, idx;
	std::cin >> max >> count >> start;
	for (int i = 0; i < count; i++)
	{
		Node n;
		std::cin >> idx >> n.target >> n.weight;
		list[idx].push_back(n);
	}
	for (int i = 1; i <= max; i++)
		distance[i] = 987654321;
	std::queue<int> q;
	q.push(start);
	distance[start] = 0;
	while (!q.empty())
	{
		auto n = q.front();
		q.pop();
		for (unsigned int i = 0; i < list[n].size(); i++)
		{
			if (distance[list[n][i].target] >= distance[n] + list[n][i].weight)
			{
				distance[list[n][i].target] = distance[n] + list[n][i].weight;
				q.push(list[n][i].target);
			}
		}
	}
	for (int i = 1; i <= max; i++)
	{
		if (distance[i] == 987654321)
			printf("INF\n");
		else
			printf("%d\n", distance[i]);
	}
	return 0;
}