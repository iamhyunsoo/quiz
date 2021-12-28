    bool canConvert(string str1, string str2) 
    {
        if (str1 == str2) return true;
        
        std::unordered_map<char, char> mp;
        std::unordered_set<char> uniqueChars;
        size_t len1 = str1.length();        
        for (size_t i = 0; i < len1; i++)
        {
            if (mp.find(str1[i]) == mp.end())
            {
                mp[str1[i]] = str2[i];    
                uniqueChars.insert(str2[i]);
            }
            else
            {
                if (mp[str1[i]] != str2[i])
                {
                    return false;
                }
            }
        }
        return uniqueChars.size() < 26 ? true : false;
    }
