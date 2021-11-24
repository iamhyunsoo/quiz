#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <utility>

class AllOne 
{
public:
	void inc(std::string key)
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

	void dec(std::string key) 
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

	std::string getMaxKey() 
	{
		return mPairs.empty() ? "" : *(mPairs.rbegin()->second.begin());
	}

	std::string getMinKey() 
	{
		return mPairs.empty() ? "" : *(mPairs.begin()->second.begin());
	}

private:
	using myPair = std::pair<int, std::unordered_set<std::string>>;
	std::list<myPair> mPairs;
	std::unordered_map <std::string, std::list<myPair>::iterator> mMap;
};
