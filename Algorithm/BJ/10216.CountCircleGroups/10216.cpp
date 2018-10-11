#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

struct Camp
{
	int X;
	int Y;
	int R;
};
bool IsGroup(const Camp& left, const Camp& right)
{
	auto dis = ::sqrt((right.X - left.X) * (right.X - left.X) + (right.Y - left.Y) * (right.Y - left.Y));
	return dis <= left.R + right.R;
}
Camp camps[3000];
bool visit[3000];
std::vector<int> nodes[3000];
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t-- > 0)
	{
		int size;
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			nodes[i].clear();
			visit[i] = false;
			Camp camp;
			std::cin >> camp.X >> camp.Y >> camp.R;
			camps[i] = camp;
		}
		for (int i = 0; i < size; i++)
		{
			for (int ii = i + 1; ii < size; ii++)
			{
				if (IsGroup(camps[i], camps[ii]))
				{
					nodes[i].push_back(ii);
					nodes[ii].push_back(i);
				}
			}
		}
		std::queue<int> q;
		int group = 0;
		for (int i = 0; i < size; i++)
		{
			if (visit[i])
				continue;
			q.push(i);
			group++;
			while (!q.empty())
			{
				auto index = q.front(); q.pop();
				visit[index] = true;
				for (int i = 0; i < nodes[index].size(); i++)
				{
					if (!visit[nodes[index][i]])
						q.push(nodes[index][i]);
				}
			}
		}
		printf("%d\n", group);
	}
	return 0;
}