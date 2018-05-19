int lateRide(int n) {
	return n % 60 % 10 + n % 60 / 10 + n / 60 % 10 + n / 60 / 10 % 10;
}

int main()
{
	lateRide(808);
	return 0;
}