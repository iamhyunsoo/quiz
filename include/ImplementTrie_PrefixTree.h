#include <string>
#include <unordered_map>

class TrieNode
{
public:
    TrieNode() : mIsEnd{false} {}
    TrieNode(char c) : mIsEnd{false} { mValue = c; }
    bool GetIsEnd() const { return mIsEnd; }
    void SetEnd(bool b) { mIsEnd = b; }
    bool IsChild(const char& c)
    {
        return mMap.find(c) != mMap.end();
    }
    void SetChild(const char& c)
    {
        mMap[c] = new TrieNode(c);
    }
    TrieNode* GetChild(const char& c)
    {
        return mMap[c];
    }

private:
    std::unordered_map<char, TrieNode*> mMap;
    bool mIsEnd;
    char mValue;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        mRoot = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(std::string word)
    {
        auto node = mRoot;
        for (size_t i = 0; i < word.length(); i++)
        {
            char& c = word[i];
            if (!(node->IsChild(c)))
            {
                node->SetChild(c);
            }
            node = node->GetChild(c); 
        }
        node->SetEnd(true);
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word)
    {
        auto node = mRoot;
        for (size_t i = 0; i < word.length(); i++)
        {
            char& c = word[i];
            if (!(node->IsChild(c)))
            {
                return false;
            }
            node = node->GetChild(c); 
        }
        return node->GetIsEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix)
    {
        auto node = mRoot;
        for (size_t i = 0; i < prefix.length(); i++)
        {
            char& c = prefix[i];
            if (!(node->IsChild(c)))
            {
                return false;
            }
            node = node->GetChild(c); 
        }
        return true; 
    }

private:
    TrieNode* mRoot;
};

