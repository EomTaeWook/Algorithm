#include<iostream>
#include <algorithm>
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t-- > 0)
	{
		int early = 0, late = 0, input, dis, count;
		std::cin >> dis >> count;
		for (int i = 0; i < count; i++)
		{
			std::cin >> input;
			early = std::max(early, std::min(dis - input, input));
			late = std::max(late, std::max(dis - input, input));
		}
		printf("%d %d\n", early, late);
	}
	return 0;
}