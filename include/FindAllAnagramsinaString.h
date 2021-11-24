std::vector<int> findAnagrams(std::string s, std::string p)
{
	const int pLen = p.length();
	const int sLen = s.length();

	if (sLen < pLen) return {};

	std::vector<int> ss(26, 0);
	std::vector<int> pp(26, 0);
	std::vector<int> ret;

	for (int i = 0; i < pLen; i++)
	{
		++ss[s[i] - 'a'];
		++pp[p[i] - 'a'];
	}
	
	if (ss == pp)
	{
		ret.push_back(0);
	}

	for (int i = pLen; i < sLen; i++)
	{
		--ss[s[i - pLen] - 'a'];
		++ss[s[i] - 'a'];

		if (ss == pp)
		{
			ret.push_back(i - pLen);
		}
	}
	return ret;
}
