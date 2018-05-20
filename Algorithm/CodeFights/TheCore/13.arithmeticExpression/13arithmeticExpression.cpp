bool arithmeticExpression(int a, int b, int c) {
	return a + b == c || a - b == c || (a / b == c && a % b == 0) || a * b == c;
}

int main()
{
	return 0;
}