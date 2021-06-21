bool isUgly(int n) 
{
	for (int i = 2; n && i < 6; i++)
	{
		while (n % i == 0)
		{
			n /= i;
		}
	}	
	return n == 1;
}