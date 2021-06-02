#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class Solution
{
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
    {
        std::unordered_map<char, std::unordered_set<std::string>> table;
        for (auto const& word : words)
        {
            if (table.count(word.back()))
            {
                table[word.back()].insert(word);
            }
            else
            {
                table.insert({ word.back(), {word} });
            }
        }

        std::vector<std::string> ret;
        std::unordered_set<std::string> found;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                char c = board[i][j];
                if (table.count(c))
                {
                    for (auto const word : table[c])
                    {
                        int idx = word.length() - 1;
                        if (!found.count(word) && help(board, word, i, j, idx))
                        {
                            ret.push_back(word);
                            found.insert(word);
                        }                   
                    }
                }
            }
        }
        return ret;
    }
private:
    bool help(std::vector<std::vector<char>>& board, std::string const& word, int i, int j, int idx)
    {
        if (idx < 0) { return true; }
        if (!IsInside(board, word, i, j, idx)) { return false; }

        char tmp = board[i][j];
        board[i][j] = '*';
        idx--;

        bool ret = help(board, word, i + 1, j, idx) 
                || help(board, word, i, j + 1, idx)
                || help(board, word, i - 1, j, idx) 
                || help(board, word, i, j - 1, idx);  

        board[i][j] = tmp;      
        return ret;
    }

    bool IsInside(std::vector<std::vector<char>>& board, std::string const& word, int const& i, int const& j, int const& idx)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[idx] != board[i][j])
        {
            return false;
        }
        return true;
    }
};