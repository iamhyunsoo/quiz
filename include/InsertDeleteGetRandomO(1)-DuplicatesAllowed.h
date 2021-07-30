#pragma once

#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mList.push_back(val);
        mDict[val].insert(mList.size() - 1);
        return mDict[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = mDict.find(val);
        if (it != mDict.end())
        {
            auto valLastPos = *(it->second.begin());
            it->second.erase(it->second.begin());

            mList[valLastPos] = mList.back();
            mDict[mList.back()].insert(valLastPos);
            mDict[mList.back()].erase(mList.size() - 1);
            mList.pop_back();

            if (it->second.empty())
            {
                mDict.erase(it);
            }

            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return mList[rand() % mList.size()];
    }

private:
    std::vector<int> mList;
    std::unordered_map<int, std::unordered_set<int>> mDict;
};
