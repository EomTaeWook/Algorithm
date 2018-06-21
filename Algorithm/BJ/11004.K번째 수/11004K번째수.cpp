#include<iostream>
#include<algorithm>
int list[5000000];
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int size, input;
	std::cin >> size >> input;;

	for (int i = 0; i < size; i++)
		std::cin >> list[i];
	std::sort(list, list + size);
	printf("%d\n", list[input - 1]);
	return 0;
}