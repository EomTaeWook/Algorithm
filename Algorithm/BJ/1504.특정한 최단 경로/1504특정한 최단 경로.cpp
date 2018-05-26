#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
struct Node
{
	int Target;
	int Distance;
};
std::vector<Node> list[801];
void Dijkstra(std::vector<long long>& distance, int start)
{
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.push(std::make_pair(0, start));
	distance[start] = 0;
	while (!q.empty())
	{
		auto dis = q.top().first;
		auto n = q.top().second;
		q.pop();
		if (dis > distance[n]) continue;
		for (size_t i = 0; i < list[n].size(); i++)
		{
			if (distance[list[n][i].Target] > dis + list[n][i].Distance)
			{
				distance[list[n][i].Target] = dis + list[n][i].Distance;
				q.push(std::make_pair(distance[list[n][i].Target], list[n][i].Target));
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int max, size, start;
	std::cin >> max >> size;
	for (int i = 0; i < size; i++)
	{
		Node n;
		std::cin >> start >> n.Target >> n.Distance;
		Node n1;
		n1.Target = start;
		n1.Distance = n.Distance;
		list[start].push_back(n);
		list[n.Target].push_back(n1);
	}
	int wayPoint1, wayPoint2;
	std::cin >> wayPoint1 >> wayPoint2;
	std::vector<int> _point = { 1, wayPoint1,  wayPoint2 };
	std::vector<std::vector<long long>> _distance;
	for (int i = 0; i < 3; i++)
	{
		_distance.push_back(std::vector<long long>(max + 1, 987654321));
		Dijkstra(_distance[i], _point[i]);
	}
	long long sum = std::min(_distance[0][wayPoint1] + _distance[1][wayPoint2] + _distance[2][max], _distance[0][wayPoint2] + _distance[1][max] + _distance[2][wayPoint1]);
	printf("%lld\n", sum >= 987654321 ? -1 : sum);
	return 0;
}