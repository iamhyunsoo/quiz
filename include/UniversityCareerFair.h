int maxEvents(std::vector<int> arrival, std::vector<int> duration)
{
	std::vector<std::vector<int>> vec;
	for (size_t i = 0; i < arrival.size(); i++)
	{
		vec.push_back({ arrival[i], duration[i] });
	}

	std::sort(vec.begin(), vec.end(), 
		[](std::vector<int> const& a, std::vector<int> const& b)
		{
			return (a[0] + a[1]) < (b[0] + b[1]);
		}
	);

	int cnt{ 0 };
	int end{ 0 };
	for (auto const& v : vec)
	{
		if (v[0] >= end)
		{
			cnt++;
			end = v[0] + v[1];
		}
	}

	return cnt;
}
