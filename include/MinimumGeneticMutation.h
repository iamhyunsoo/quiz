class Genetic 
{
public:
	int minMutation(string start, string end, vector<string>& bank)
	{
		std::unordered_set<std::string> sets{ bank.begin(), bank.end() };
		std::queue<std::string> possibleNext;
		int cnt{ 0 };

		possibleNext.push(start);
		while (!possibleNext.empty())
		{
			for (int i = possibleNext.size(); i > 0; i--)
			{
				std::string word = possibleNext.front();
				possibleNext.pop();
				if (word == end)
				{
					return cnt;
				}
				FindNextMutation(word, possibleNext, sets);
			}
			cnt++;
		}
		return -1;
	}

	void FindNextMutation(std::string word, std::queue <std::string>& possibleNext, std::unordered_set<std::string>& sets)
	{
		sets.erase(word);
		for (int i = 0; i < word.size(); i++)
		{
			auto tmp = word[i];
			for (char c : "ACGT")
			{
				word[i] = c;

				if (sets.find(word) != sets.end())
				{
					possibleNext.push(word);
				}
			}
			word[i] = tmp;
		}
	}
};
