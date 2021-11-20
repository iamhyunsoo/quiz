std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) 
{
    std::unordered_map<std::string, int> mp;
    for (auto const& word : words)
    {
        mp[word]++;
    }

    std::vector<std::pair<std::string, int>> pairs;
    for (auto& it : mp)
    {
        pairs.push_back(it);
    }

    auto cmp = [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b)
    {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };

    std::sort(pairs.begin(), pairs.end(), cmp);


    std::vector<std::string> ret;
    for (auto const& it : pairs)
    {
        ret.push_back(it.first);
        k--;
        if (k == 0)
        {
            break;
        }
    }

    return ret;
}
