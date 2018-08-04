#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
long long list[501] = {40, 30, 30, 50};
long long memo[501][501];


long long Recursive(int index, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == index)
			continue;

	}
	return 0;
}
int main()
{
	int t=0, tc = 1, size = 4;
	//std::cin >> tc;
	while (t++ < tc)
	{
		//40 30 30 50
		//std::cin >> size;
		/*for (int i = 0; i < size; i++)
			std::cin >> list[i];*/
		memset(memo, -1, sizeof(memo));

		printf("%lld\n", Recursive(0, size));
	}
	return 0;
}