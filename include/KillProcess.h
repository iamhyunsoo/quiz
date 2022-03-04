class Solution
{
public:
    std::vector<int> killProcess(std::vector<int>& pid, std::vector<int>& ppid, int kill) 
    {
        std::unordered_map<int, std::vector<int>> mp;
        for (size_t i = 0; i < ppid.size(); i++)
        {
            if (ppid[i] > 0)
            {
                if (mp.find(ppid[i]) == mp.end())
                {
                    mp[ppid[i]] = {}; 
                }
                std::vector<int>& parent = mp[ppid[i]];
                parent.push_back(pid[i]);
            }
        }
        
        std::vector<int> ret;
        ret.push_back(kill);
        helper(mp, kill, ret);
        return ret;
    }
    void helper(std::unordered_map<int, std::vector<int>>& mp, int kill, std::vector<int>& ret)
    {
        for (auto const& child : mp[kill])
        {
            ret.push_back(child);
            helper(mp, child, ret);
        }
    }
};
