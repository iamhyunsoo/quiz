class Solution 
{
public:
    int uniqueLetterString(std::string s) 
    {
        int sum {0};
        std::vector<int> contribution(26, 0);
        std::vector<int> lastCont(26, 0);
        
        int cur {0};
        for (size_t i = 0; i < s.length(); i++)
        {
            char& c = s[i];
            cur -= contribution[c - 'A'];
            contribution[c - 'A'] = i - (lastCont[c - 'A'] - 1);
            cur += contribution[c - 'A'];
            lastCont[c - 'A'] = i + 1;
            sum += cur;
        }
        return sum;
    }
};


#ifdef TLE
class Solution 
{
public:
    int uniqueLetterString(string s) 
    {
        int sum {0};
        for (int len = 1; len <= s.length(); len++)
        {
            for (int i = 0; i + len <= s.length(); i++)
            {
                sum += countUniqueChars(s.substr(i, len));
            }
        }
        return sum;
    }
private:
    int countUniqueChars(std::string s)
    {
        std::unordered_map<char, int> mp;
        for (auto const& c : s)
        {
            mp[c]++;
        }
        int uniq {0};
        for (auto& m : mp)
        {
            if (m.second == 1)
            {
                uniq++;
            }
        }
        return uniq;
    }
};
#endif
