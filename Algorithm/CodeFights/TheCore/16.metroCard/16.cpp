#include<vector>
std::vector<int> metroCard(int lastNumberOfDays) {

	if (lastNumberOfDays == 30) return std::vector<int> { 31 };

	else if (lastNumberOfDays == 31) return std::vector<int> { 28, 30, 31 };

	else return std::vector<int> { 31 };

}
int main()
{
	metroCard(30);
	return 0;
}