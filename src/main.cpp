#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

#include <NumberofIslands2.h>
int main()
{
    Solution s;
    vector<vector<int>> vec = {{0,0}, {0,1}, {1,2}, {2,1}};
    for (auto x : s.numIslands2(3, 3, vec))
    {
        cout << x << ", ";
    }
}