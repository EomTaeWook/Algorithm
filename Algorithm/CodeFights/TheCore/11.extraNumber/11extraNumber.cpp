int extraNumber(int a, int b, int c) {
	return a == b ? c : a == c ? b : a;
}
int main()
{
	extraNumber(2, 7, 2);
	return 0;
}