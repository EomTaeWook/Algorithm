
#include <iostream>
#include <string.h>

int list[300000];
std::pair<int, int> tree[600001];

std::pair<int, int> SegmentTree(int left, int right, int node)
{
	if (left >= right)
	{
		tree[node].first = list[left];
		tree[node].second = 1;
		return tree[node];
	}
	auto l = SegmentTree(left, (left + right) / 2, node * 2);
	auto r = SegmentTree((left + right) / 2 + 1, right, node * 2 + 1);
	if (l.second == r.second)
	{
		tree[node].first = 0;
		tree[node].second = l.second;
	}
	else if(l.second > r.second)
	{
		tree[node].first = l.first;
		tree[node].second += l.second;
	}
	else
	{
		tree[node].first = r.first;
		tree[node].second += r.second;
	}
	return tree[node];
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int size, count;
	std::cin >> size >> count;
	for (int i = 0; i < size; i++)
		std::cin >> list[i];

	SegmentTree(0, size - 1, 1);

	/*int M, begin, end;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> begin >> end;
		memset(color, 0, sizeof(color));
		bool check = false;
		for (int ii = begin - 1; ii < end; ii++)
		{
			color[list[ii] - 1]++;
			if (color[list[ii] - 1] > (end - begin + 1) / 2)
			{
				printf("yes %d\n", list[ii]);
				check = true;
				break;
			}
		}
		if (!check)
			printf("no\n");
	}*/
	return 0;
}