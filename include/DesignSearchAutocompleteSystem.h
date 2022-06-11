class AutocompleteSystem 
{
	std::vector<std::pair<std::string, int>> mData;
	std::string mInput;
public:
    AutocompleteSystem
	(
		std::vector<std::string>& sentences, 
		std::vector<int>& times
	) 
	{
		for (size_t i = 0; i < sentences.size(); ++i)
		{
			mData.push_back(std::make_pair(sentences[i], times[i]));
		}
		std::sort(mData.begin(), mData.end(), 
		[](std::pair<std::string, int>& a, std::pair<std::string, int>& b){
			return (a.second == b.second) ? a.first < b.first : a.second > b.second;
		});
    }
    
    std::vector<std::string> input(char c) 
	{
		if (c == '#')
		{
			bool isInside = false;
			for (size_t i = 0; i < mData.size(); ++i)
			{
				if (mData[i].first == mInput)
				{
					isInside = true;
					mData[i].second++;
					break;
				}
			}
			if (!isInside)
			{
				mData.push_back(std::make_pair(mInput, 1));
			}
			std::sort(mData.begin(), mData.end(), 
			[](std::pair<std::string, int>& a, std::pair<std::string, int>& b){
				return (a.second == b.second) ? a.first < b.first : a.second > b.second;
			});
			
			mInput.clear();
			return {};
		}
		else
		{
			mInput += c;
		}

		int size {0};
		std::vector<std::string> results;
		for (auto const& x : mData)
		{
			if (x.first.starts_with(mInput))
			{
				results.push_back(x.first);	
				size++;
			}	

			if (size == 3)
			{
				break;
			}
		}
		return results;
    }
};
