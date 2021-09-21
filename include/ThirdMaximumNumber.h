
int thirdMax(vector<int>& nums) 
{
	long first = LONG_MIN;
	long second = LONG_MIN;
	long third = LONG_MIN;

	for (int const& num : nums) 
	{
		if (num == first || num == second || num == third)
			continue;

		if (num > first) 
		{
			third = second;
			second = first;
			first = num;
		}
		else if (num > second) 
		{
			third = second;
			second = num;
		}
		else if (num > third) 
		{
			third = num;
		}
	}
	return third == LONG_MIN ? first : third;
}

int thirdMax2(std::vector<int>& nums) 
{
	std::set<int> s;
	for (int const& num : nums)
	{
		if (s.insert(num).second && s.size() > 3)
		{
			s.erase(s.begin());
		}
	}
	return s.size() == 3 ? *s.begin() : *s.rbegin();
}
