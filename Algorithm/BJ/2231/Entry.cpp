#include <iostream>
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int input = 0, output =0, sum = 0, temp = 0;
	std::cin >> input;
	for(int i= 0; i<input; i++)
	{
		temp = sum = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == input)
		{
			output = i;
			break;
		}
	}
	printf("%d\n", output == input ? 0 : output);
	return 0;
}