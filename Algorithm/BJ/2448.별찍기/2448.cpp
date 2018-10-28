#include<iostream>
#include <string>
#include <vector>

void Star(std::vector<std::string>& output, const int&& count)
{
	if (count == 1)
		return;
	output.push_back(output[0] + output[0]);
	output.push_back(output[1] + output[1]);
	output.push_back(output[2] + output[2]);
	Star(output, count - 1);
}

int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	std::ios::ios_base::sync_with_stdio(false);
	int N = 12;
	//std::cin >> N;
	std::vector<std::string> ouput = 
	{ 
		{ "..*..." },
		{ ".*.*.." },
		{ "*****." }
	};
	if (N == 3)
	{
		for (int i = 0; i < 3; i++)
			printf("%s\n", ouput[i].c_str());
	}
	else
	{
		Star(ouput, N / 3);
		std::string space(".");
		for (int i = 0; i < N/2; i++)
		{
			for (int ii = 0; ii < N / 2 - i; ii++)
			{
				ouput[i].insert(0, space);
			}
		}
		for (int i = 0; i < N; i++)
			printf("%s\n", ouput[i].c_str());
	}
	return 0;
}