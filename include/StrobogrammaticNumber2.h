class Solution 
{
    std::vector<std::vector<std::string>> mStrobo = {{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
public:
    vector<string> findStrobogrammatic(int n) 
    {
        return getStrobo(n, n);
    }
private:
    vector<string> getStrobo(int n, int orgN)
    {
        if (n == 0) { return {""}; }
        else if (n == 1) { return { "0", "1", "8" }; }
        auto strobos = getStrobo(n - 2, orgN);
        std::vector<std::string> ret;
        for (auto prev : strobos) 
        {
            for (auto nums : mStrobo)
            {
                if (nums[0] != "0" || n != orgN)
                {
                    ret.push_back(nums[0] + prev + nums[1]);
                }
            }
        }
        return ret;
    }
};
