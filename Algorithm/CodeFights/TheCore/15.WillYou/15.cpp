bool willYou(bool young, bool beautiful, bool loved) {
	return (young & beautiful) ^ loved;
}
int main()
{
	willYou(true, true, true);
	return 0;
}

