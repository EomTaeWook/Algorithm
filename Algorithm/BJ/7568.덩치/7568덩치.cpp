#include <iostream>
int list[50][50];
int visit[50];
int main()
{
	std::ios_base::sync_with_stdio(false);
	int count;
	std::cin >> count;
	for (int i = 0; i < count; i++)
		std::cin >> list[i][0] >> list[i][1];
	for (int i = 0; i < count; i++)
	{
		int rank = count;
		for (int ii = 0; ii < count; ii++)
		{
			if (i == ii) continue;
			if (list[i][0] >= list[ii][0] || list[i][1] >= list[ii][1])
				rank--;
		}
		visit[i] = rank;
	}
	for (int i = 0; i < count; i++)
		printf("%d ", visit[i]);
	printf("\n");
	return 0;
}