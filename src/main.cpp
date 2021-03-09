#include "FourSum.h"

#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Solution s;
    vector<int> fd{0,0,0,0};
    vector<int> fs{2,1,0,-1};
    for (auto  x : Solution1::fourSum(fd, 0))
    {
        for (auto y : x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}