#include<iostream>
#include<vector>
#include<tuple>
int main()
{
	std::vector<std::tuple<int, int, int>> nodes;
	int dis[501];

	std::ios::ios_base::sync_with_stdio(false);
	int N = 3, M = 4, a,b,c;
	std::fill(dis, dis + 501, 987654321);
	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> a >> b >> c;
		nodes.emplace_back(std::make_tuple(a, b, c));
	}
	dis[1] = 0;
	bool isCycles = false;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t ii = 0; ii < M; ii++)
		{
			auto p = nodes[ii];
			if (dis[std::get<0>(p)] != 987654321 && dis[std::get<1>(p)] > dis[std::get<0>(p)] + std::get<2>(p))
				dis[std::get<1>(p)] = dis[std::get<0>(p)] + std::get<2>(p);
		}
	}
	for (size_t i = 0; i < M; i++)
	{
		auto p = nodes[i];
		if (dis[std::get<0>(p)] != 987654321 && dis[std::get<1>(p)] > dis[std::get<0>(p)] + std::get<2>(p))
		{
			isCycles = true;
			break;
		}
	}
	if(isCycles)
		printf("-1\n");
	else
	{
		for (int i = 2; i <= N; i++)
			printf("%d\n", dis[i] == 987654321 ? -1 : dis[i]);
	}
	return 0;
}