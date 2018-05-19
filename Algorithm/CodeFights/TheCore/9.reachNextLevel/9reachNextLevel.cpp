bool reachNextLevel(int experience, int threshold, int reward) {
	return  experience + reward >= threshold;
}
int main()
{
	reachNextLevel(10, 15, 5);
	return 0;
}