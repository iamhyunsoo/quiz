class Solution 
{
public:
    std::vector<int> lexicalOrder(int n) 
    {
        std::vector<int> ret;
        help(ret, 1, n);
        return ret;
    }
private:
    void help(std::vector<int>& ret, int curr, int n)
    {
        if (curr > n) return;
        ret.push_back(curr);
        help(ret, curr * 10, n);
        
        if (curr % 10 != 9)
        {
            help(ret, curr + 1, n);
        }
    }
};
