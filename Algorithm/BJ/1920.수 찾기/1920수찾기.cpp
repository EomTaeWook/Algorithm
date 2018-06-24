#include<iostream>
#include<algorithm>
int list[100000];
int max;
int Search(int find, int front, int end)
{
	if (list[(front + end) / 2] == find) return 1;
	if (front == end) return 0;
	if(list[(front + end) / 2] > find)
		return Search(find, front, (front + end) / 2);
	else
		return Search(find, (front + end) / 2 + 1, end);
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::cin >> max;
	for (int i = 0; i < max; i++)
		std::cin >> list[i];
	std::sort(list, list + max);
	int size, input;
	std::cin >> size;
	for (auto i = 0; i < size; i++)
	{
		std::cin >> input;
		printf("%d\n", Search(input, 0, max - 1));
	}
	return 0;
}