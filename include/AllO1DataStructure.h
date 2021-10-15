class AllOne 
{
public:
	void inc(string key)
	{
		if (mMap.find(key) == mMap.end())
		{
			mMap[key] = mPairs.insert(mPairs.begin(), { 0, {key} });
		}
		
		std::list<myPair>::iterator next = mMap[key];
		std::list<myPair>::iterator curr = next++;
		if (next == mPairs.end() || curr->first + 1 < next->first)
		{
			next = mPairs.insert(next, { curr->first + 1, {} });
		}

		next->second.insert(key);
		mMap[key] = next;

		curr->second.erase(key);
		if (curr->second.empty())
		{
			mPairs.erase(curr);
		}
	}

	void dec(string key) 
	{
		if (mMap.find(key) == mMap.end())
		{
			return;
		}
		std::list<myPair>::iterator prev = mMap[key];
		std::list<myPair>::iterator curr = prev--;
		mMap.erase(key);
		
		if (curr->first > 1)
		{
			if (curr == mPairs.begin() || prev->first + 1 < curr->first)
			{
				prev = mPairs.insert(curr, { curr->first - 1, {} });
			}
			prev->second.insert(key);
			mMap[key] = prev;
		}

		curr->second.erase(key);
		if (curr->second.empty())
		{
			mPairs.erase(curr);
		}
	}

	string getMaxKey() 
	{
		return mPairs.empty() ? "" : *(mPairs.rbegin()->second.begin());
	}

	string getMinKey() 
	{
		return mPairs.empty() ? "" : *(mPairs.begin()->second.begin());
	}

private:
	using myPair = std::pair<int, std::unordered_set<std::string>>;
	std::list<myPair> mPairs;
	std::unordered_map <std::string, std::list<myPair>::iterator> mMap;
};
