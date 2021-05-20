#include <unordered_map>

class TwoSum
{
public:
    void add(int num)
    {
        mMap[num]++;
    }

    bool find(int value)
    {
        for (auto& x : mMap)
        {
            int tmp = value - x.first;
            if ((tmp != x.first && mMap.count(tmp)) || (tmp == x.first && x.second > 1))
            {
                return true;
            }
        }
        return false;
    }

private:
    std::unordered_map<int, int> mMap;
};