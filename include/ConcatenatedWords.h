class Solution 
{
public:
    vector<string> findAllConcatenatedWordsInADict(std::vector<string>& words)  //Time Limit Exceeded..
    {
        std::sort(words.begin(), words.end(), 
                  [](std::string const& a, std::string const& b)
                  {
                      return a.length() < b.length();    
                  });
        
        std::unordered_set<std::string> st;
        std::vector<std::string> ret;
        
        for (auto const& word : words)
        {
            if (helper(word, st))
            {
                ret.push_back(word);
            }
            st.insert(word);
        }
        return ret;
    }
    
private:
    bool helper(std::string const& word, std::unordered_set<std::string>& st)
    {
        if (st.empty()) return false;
        std::vector<bool> dp(word.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= word.length(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (dp[j])
                {
                    if (st.find(word.substr(j, i - j)) != st.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[word.length()];
    }
};
