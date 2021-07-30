int getSumRecur(int a, int b) //Recursive
{
	return b == 0 ? a : getSumRecur(a ^ b, (a & b) << 1);
}

int getSumIter(int a, int b) //Iterative
{
	int tmp{ 0 };
	while (b)
	{
		tmp = (a & b);
		a = a ^ b;
		b = tmp << 1;
	}
	return a;
}