class Solution {
public:
    vector<string> printVertically(string s) {
        std::vector<std::string> words;
        std::istringstream iss(s);
        std::string word;
        size_t max_len = 0;
        while (std::getline(iss, word, ' '))
        {
            max_len = std::max(max_len, word.length());
            words.push_back(word);
        }

        std::vector<std::string> res(max_len, "");
        for (int i = 0; i < max_len; ++i)
        {
            for (int j = 0; j < (int)words.size(); ++j)
            {
                if (words[j].length() > i)
                {
                    res[i] += words[j][i];
                }
                else
                {
                    res[i] += " ";
                }
            }
            res[i] = rtrim(res[i]);
        }

        return res;
    }

    std::string & rtrim(std::string & str)
    {
    auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
    str.erase( it1.base() , str.end() );
    return str;   
    }
};
