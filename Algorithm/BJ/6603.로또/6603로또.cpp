#include<iostream>
#include<vector>
std::vector<int> _stack;
void Recursive(std::vector<int>&list, int idx)
{
	if (_stack.size() == 6)
	{
		for (auto i = 0; i < _stack.size(); i++)
			printf("%d ", _stack[i]);
		printf("\n");
		return;
	}
	if (list.size() <= idx) return;
	for (int i = idx; i < list.size(); i++)
	{
		_stack.push_back(list[i]);
		Recursive(list, i + 1);
		_stack.pop_back();
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int t, input;
	std::vector<int> _list;
	while (true)
	{
		std::cin >> t;
		if (t == 0)break;
		_list.clear();
		for (int i = 0; i < t; i++)
		{
			std::cin >> input;
			_list.push_back(input);
		}
		Recursive(_list, 0);
		printf("\n");
	}
	return 0;
}