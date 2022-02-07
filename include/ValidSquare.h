class Solution 
{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        std::unordered_set<int> st;
        st.insert(GetDistance(p1, p2));
        st.insert(GetDistance(p1, p3));
        st.insert(GetDistance(p1, p4));
        st.insert(GetDistance(p2, p3));
        st.insert(GetDistance(p2, p4));
        st.insert(GetDistance(p3, p4));
        
        return st.size() == 2 ? (st.find(0) == st.end() ? true : false) : false;
    }
private:
    int GetDistance(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
