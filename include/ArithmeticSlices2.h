int numberOfArithmeticSlices(vector<int> nums) 
{
	int size = nums.size();
	int ret{ 0 };

	std::vector<std::unordered_map<long, int>> table(size);
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			long diff = (long)nums[i] - nums[j];
			int cnt = table[j].count(diff) ? table[j][diff] : 0;
			ret += cnt;

			table[i][diff] += cnt + 1;
		}
	}
	re
