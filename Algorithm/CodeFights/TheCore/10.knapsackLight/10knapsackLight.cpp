#include <algorithm>
int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
	if (weight1 + weight2 <= maxW) return value1 + value2;
	int max = 0;
	if (weight1 <= maxW)
		max = std::max(value1, max);
	if (weight2 <= maxW)
		max = std::max(value2, max);
	return max;
}
int main()
{
	knapsackLight(10, 5, 6, 4, 8);
	return 0;
}