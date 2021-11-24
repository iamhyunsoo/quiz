string reorganizeString(string s) 
{
    const int len = s.length();
    if (len == 0)
    {
        return "";
    }

    std::unordered_map<char, int> mp;
    char biggestChar;
    int biggestFreq = 0;
    for (auto const& c : s)
    {
        mp[c]++;
        if (mp[c] > biggestFreq)
        {
            biggestChar = c;
            biggestFreq = mp[c];
        }
    }

    // aaabb : (5 +1) / 2 = 3 (6+1) / 2 = 3
    // ababa, ababab
    // aaaabb 
    if (biggestFreq > (s.length() +1) / 2 ) return "";

    // aaabb
    // ret = [ , , , ,  ]
    // ret = a b a b a

    // ret = a, b,a, b,a
    std::string ret(len, 'a');
    int idx = 0;
    while (mp[biggestChar] > 0)
    {
        ret[idx] = biggestChar;
        mp[biggestChar]--;
        idx += 2;
    }

    for (auto& it : mp)
    {
        while(it.second)
        {
            if (idx >= len)
            {
                idx = 1;
            }
            ret[idx] = it.first;
            it.second--;
            idx += 2;
        }
    }
    return ret;
}
