 int numberOfArithmeticSlices(std::vector<int>& nums) {
	int ret{ 0 };
	int strike{ 0 };
	for (int i = 2; i < nums.size(); i++)
	{
		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
		{
			strike++;
			ret += strike;
		}
		else
		{
			strike = 0;
		}
	}
	return ret;
}
