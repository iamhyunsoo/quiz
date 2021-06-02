#include <cstring>
#include <string>

struct TrieNode
{
    bool mEnd;
    TrieNode* mChilds[26];
  
    TrieNode() : mEnd{false}
    {
        memset(mChilds, NULL, sizeof(mChilds));
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        mRoot = new TrieNode();
    }

    void addWord(std::string word)
    {
        TrieNode* tmp = mRoot;
        for (size_t i = 0; i < word.length(); i++)
        {
            int no = word[i] - 'a';
            if (!tmp->mChilds[no])
            {
                tmp->mChilds[no] = new TrieNode();
            }
            tmp = tmp->mChilds[no];
        }
        tmp->mEnd = true;
    }

    bool search(std::string word)
    {
        return searchHelp(word, mRoot);
    }

private:
    bool searchHelp(std::string word, TrieNode* root)
    {
        for (size_t i = 0; i < word.length(); i++)
        {
            if (word[i] != '.')
            {
                if (!root->mChilds[word[i] - 'a'])
                {
                    return false;
                }
                root = root->mChilds[word[i] - 'a'];
            }
            else
            {
                bool isFound {false};
                int j {0};
                for (; j < 26; j++)
                {
                    if (root->mChilds[j])
                    {
                        isFound |= searchHelp(word.substr(i + 1), root->mChilds[j]);
                    }
                    if (isFound)
                    {
                        return true;
                    }
                }
                if (j == 26)
                {
                    return false;
                }
            }
        }
        return root->mEnd;
    }

private:
    TrieNode* mRoot;
};
