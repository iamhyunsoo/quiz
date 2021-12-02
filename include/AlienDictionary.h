class Solution 
{
public:
    string alienOrder(vector<string>& words) 
    {
        // words = ["wrt","wrf","er","ett","rftt"]
        
        // a -> b- > c ->d ::for human
        
        // t -> f
        // w -> e
        // r -> t
        // e -> r       // w->e->r->t->f
        
        std::unordered_map<char, std::multiset<char>> mp;
        std::unordered_map<char, int> freq;
        
        for (auto const& word :words)
        {
            for (auto const& ch : word)
            {
                freq[ch] = 0;
            }
        }
        
        for (size_t i = 0; i < words.size() - 1; i++)
        {
            if (words[i].length() > words[i+1].length() && words[i].compare(0, words[i+1].length(), words[i+1]) == 0)
            {
                return "";
            }
            
            for (size_t j = 0; j < std::min(words[i].length(), words[i+1].length()); j++)
            {
                if (words[i][j] != words[i+1][j])
                {
                    mp[words[i][j]].insert(words[i+1][j]);
                    freq[words[i+1][j]]++;
                    break;
                }
            }
        }

        
        // freq = w e r t f
        //        0 1 1 1 1
        
        // mp =  w   e   r   t   f 
        //      {e},{r},{t} {f}  {}

        
        std::queue<char> que;
        for (auto const& it : freq)
        {
            if (it.second == 0)
            {
                que.push(it.first);
            }
        }
        
        std::string ret = "";
        while (!que.empty())
        {
            char letter = que.front();
            que.pop();
            
            ret += letter;
            
            auto nextChars = mp[letter];  //std::set<char>
            
            for (auto it : nextChars)
            {
                freq[it]--;
                
                if (freq[it] == 0)
                {
                    que.push(it);
                }
            }
            
        }
        
        // When there's a cycle like ["a", "b", "c", "a"]
        if (ret.length() < freq.size())
        {
            return "";
        }
        
        return ret;
    }
};
