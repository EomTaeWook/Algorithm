#include<iostream>
int paper[2187][2187], count[3];
int max;
bool Check(int size, int x, int y)
{
	auto value = paper[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int ii = x; ii < x + size; ii++)
		{
			if (value != paper[i][ii])
				return false;
		}
	}
	return true;
}
void Recursion(int size, int x, int y)
{
	if (size <= 0) return;
	if (Check(size, x, y))
		count[paper[y][x] + 1]++;
	else
	{
		Recursion(size / 3, x, y);
		Recursion(size / 3, x + size / 3, y);
		Recursion(size / 3, x + size / 3 * 2, y);
		Recursion(size / 3, x, y + size / 3);
		Recursion(size / 3, x + size / 3, y + size / 3);
		Recursion(size / 3, x + size / 3 * 2, y + size / 3);
		Recursion(size / 3, x, y + size / 3 * 2);
		Recursion(size / 3, x + size / 3, y + size / 3 * 2);
		Recursion(size / 3, x + size / 3 * 2, y + size / 3 * 2);
	}
}
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	std::cin >> max;
	for (int i = 0; i < max; i++)
	{
		for (int ii = 0; ii < max; ii++)
			std::cin >> paper[i][ii];
	}
	Recursion(max, 0, 0);
	printf("%d\n%d\n%d\n", count[0], count[1], count[2]);
	return 0;
}