#include<iostream>
char stars[3072][6144];
void Star(const int& x , const int& y, const int& N)
{
	if (N == 3)
	{
		stars[y][x] = '*';
		stars[y + 1][x - 1] = '*';
		stars[y + 1][x + 1] = '*';
		stars[y + 2][x - 2] = '*';
		stars[y + 2][x - 1] = '*';
		stars[y + 2][x] = '*';
		stars[y + 2][x + 1] = '*';
		stars[y + 2][x + 2] = '*';
		return;
	}
	Star(x, y, N / 2);
	Star(x - N / 2, y + N / 2, N / 2);
	Star(x + N / 2, y + N / 2, N / 2);
}

int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int N = 6;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int ii = 0; ii < N * 2 - 1; ii++)
			stars[i][ii] = ' ';
	}
	Star(N - 1, 0, N);
	for (int i = 0; i < N; i++)
	{
		printf("%s", stars[i]);
		printf("\n");
	}
	return 0;
}