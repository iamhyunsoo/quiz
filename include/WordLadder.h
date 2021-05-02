#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> s1;
    unordered_set<string> s2;
    unordered_set<string> list(wordList.begin(), wordList.end());

    int level = 0;
    s1.insert(beginWord);
    s2.insert(endWord);
    while (!s1.empty())
    {
        level++;
        if (s1.size() > s2.size())
        {
            std::swap(s1, s2);
        }
        
        unordered_set<string> curr;
        for (auto word : s1)
        {    
            
            for (int i = 0; i < word.length(); i++)
            {
                auto saved = word[i];
                for (char c = 'a'; c != 'z'; c++)
                {
                    word[i] = c;
                    if (s2.find(word) != s2.end())
                    {
                        return level + 1;
                    }
                    if (list.find(word) == list.end())
                    {
                        continue;
                    }
                    list.erase(word);
                    curr.insert(word);
                }
                word[i] = saved;
            }
        }
        s1 = curr;
    }
    return 0;
}
