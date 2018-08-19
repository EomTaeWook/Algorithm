#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
int memo[1001][1001] = { 0 };
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::string input1, input2;;
	std::cin >> input1 >> input2;
	input1 = input1.insert(0, "0");
	input2 = input2.insert(0, "0");
	for (int i = 1; i < input1.size(); i++)
	{
		for (auto ii = 1; ii < input2.size(); ii++)
		{
			if (input1[i] == input2[ii])
				memo[i][ii] = memo[i - 1][ii - 1] + 1;
			else
				memo[i][ii] = std::max(memo[i][ii - 1], memo[i - 1][ii]);
		}
	}
	std::stack<char> stack;
	int i = input1.size()-1;
	int ii = input2.size()-1;
	while (ii > 0 && i > 0)
	{
		if (input1[i] == input2[ii])
		{
			stack.push(input2[ii]);
			ii--; i--;
		}
		else
		{
			if (memo[i - 1][ii] > memo[i][ii-1])
				i--;
			else
				ii--;
		}
	}
	printf("%d\n",stack.size());
	while(!stack.empty())
	{
		printf("%c", stack.top());
		stack.pop();
	}
	printf("\n");
	return 0;
}