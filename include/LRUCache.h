#include <list>
#include <unordered_map>

struct Dict
{
    int mVal;
    std::list<int>::iterator mIter;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    : mCapacity{capacity}
    {}

    int get(int key)
    {
        if (mDict.find(key) != mDict.end())
        {
            mKeys.erase(mDict[key].mIter);
            mKeys.push_front(key);
            mDict[key].mIter = mKeys.begin();
            return mDict[key].mVal;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mDict.find(key) != mDict.end())
        {
            mKeys.erase(mDict[key].mIter);
        }
        else
        {
            if (mDict.size() == mCapacity)
            {
                mDict.erase(mKeys.back());
                mKeys.pop_back();
            }   
        }
        mKeys.push_front(key);
        mDict[key] = {value,mKeys.begin()};
        
        return;
    }

private:
    std::list<int> mKeys;
    std::unordered_map<int, Dict> mDict;
    int mCapacity;
};