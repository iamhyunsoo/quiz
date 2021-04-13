#include <algorithm>
#include <stack>
#include <vector>

using std::vector;
using std::stack;
int largestRectangleArea(vector<int>& heights)
{
    if (heights.empty())
    {
        return 0;
    }

    stack<int> st;
    int ret {0};    
    heights.push_back(0);
    
    for (int i = 0; i < heights.size(); i++)
    {
        while (st.size() && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.size() ? st.top() : -1;
            ret = std::max(ret, (height * (i - 1 - width)));
        }
        st.push(i);
    }
    return ret;
}