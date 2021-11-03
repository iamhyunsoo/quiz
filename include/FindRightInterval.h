std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) 
{
	std::vector<int> ret;
	std::map<int, int> table;
	for (int i = 0; i < intervals.size(); i++)
	{
		table[intervals[i][0]] = i;
	}

	for (std::vector<int> const& interval : intervals)
	{
		auto it = table.lower_bound(interval[1]);
		if (it != table.end())
		{
			ret.push_back(it->second);
		}
		else
		{
			ret.push_back(-1);
		}
	}

	return ret;
}
