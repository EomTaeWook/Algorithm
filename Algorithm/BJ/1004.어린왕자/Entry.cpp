#include <iostream>
#include <math.h>
struct Point
{
	int X;
	int Y;
};
struct Planet : Point
{
	int R;
};
int main()
{
	std::ios::ios_base::sync_with_stdio(false);
	int t = 0;
	std::cin >> t;
	Point points[2];
	while (t-- > 0)
	{
		int count = 0;
		std::cin >> points[0].X >> points[0].Y >> points[1].X >> points[1].Y;
		int planet;
		std::cin >> planet;
		for (int i = 0; i < planet; i++)
		{
			Planet p;
			std::cin >> p.X >> p.Y >> p.R;
			auto begin = std::sqrt(std::pow((p.X - points[0].X), 2) + std::pow(p.Y - points[0].Y, 2));
			auto end = std::sqrt(std::pow((p.X - points[1].X), 2) + std::pow(p.Y - points[1].Y, 2));
			if (begin < p.R && end > p.R)
				count++;
			else if (begin > p.R&&end < p.R)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}