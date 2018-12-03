#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::string T, P;
	std::getline(std::cin, T);
	std::getline(std::cin, P);

	std::vector<int> pi(P.size(), 0);
	int idx = 0;
	for (size_t i = 1; i < P.size(); i++)
	{
		while (idx > 0 && P[idx] != P[i])
			idx = pi[idx - 1];
		if (P[idx] == P[i])
			pi[i] = ++idx;
	}
	idx = 0;
	std::vector<int> ans;
	for (size_t i = 0; i < T.size(); i++)
	{
		while (idx > 0 && T[i] != P[idx])
			idx = pi[idx - 1];
		if (T[i] == P[idx])
		{
			if (idx == P.size() - 1)
			{
				ans.push_back(i - idx + 1);
				idx = pi[idx];
			}
			else
				idx++;
		}
	}
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i);
	printf("\n");
	return 0;
}
