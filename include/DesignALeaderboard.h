#include <set>
#include <unordered_map>
class Leaderboard 
{
public:
    Leaderboard() 
    {

    }

    void addScore(int playerId, int score) 
    {
        mSet.erase({ mMap[playerId], playerId });
        mMap[playerId] += score;
        mSet.insert({ mMap[playerId], playerId });
    }

    int top(int K) 
    {
        int sum{ 0 };
        int i{ 0 };
        for (auto it = mSet.rbegin(); it != mSet.rend() && i < K; it++, i++)
        {
            sum += it->first;
        }
        return sum;
    }

    void reset(int playerId) 
    {
        mSet.erase({ mMap[playerId], playerId });
        mMap[playerId] = 0;
    }
private:
    std::set<std::pair<int, int>> mSet;// <score, playerId>
    std::unordered_map<int, int> mMap; // <playerId, score>
};
