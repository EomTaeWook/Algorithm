bool isInfiniteProcess(int a, int b) {
	return ((a - b) & 1) || a > b;
}
int main()
{
	isInfiniteProcess(5, 10);
	return 0;
}