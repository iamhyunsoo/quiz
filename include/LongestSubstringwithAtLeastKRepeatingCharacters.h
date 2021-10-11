class Solution
{
public:
    int longestSubstring(string s, int k) 
    {
        int uniqueNumChars = GetNumberUniqueChar(s);
        int ret{ 0 };
        int len = s.length();
        int freq[26] = { 0 };

        for (int i = 1; i <= uniqueNumChars; i++)
        {
            memset(freq, 0, sizeof(freq));
            int startIdx{ 0 };
            int endIdx{ 0 };
            int unique{ 0 };
            int uniqueWithK{ 0 };
            while (endIdx < len)
            {
                if (unique <= i)
                {
                    int tmp = s[endIdx++] - 'a';
                    if (freq[tmp]++ == 0)
                    {
                        unique++;
                    }

                    if (freq[tmp] == k)
                    {
                        uniqueWithK++;
                    }
                }
                else
                {
                    int tmp = s[startIdx++] - 'a';

                    if (freq[tmp]-- == k)
                    {
                        uniqueWithK--;
                    }

                    if (freq[tmp] == 0)
                    {
                        unique--;
                    }
                }

                if (unique == i && unique == uniqueWithK)
                {
                    ret = std::max(ret, (endIdx - startIdx));
                }
            }
        }
        return ret;
    }

private:
    int GetNumberUniqueChar(std::string& s)
    {
        std::unordered_set<char> m;
        for (auto const& c : s)
        {
            m.insert(c);
        }
        return static_cast<int>(m.size());
    }
};
