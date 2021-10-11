int firstUniqChar(std::string s) 
{
    std::vector<int> dict(26, 0);
    for (auto const& c : s)
    {
        dict[c - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}
