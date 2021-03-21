
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "CombinationSum.h"

using namespace std;

int main()
{
    Solution s;
    vector<int> can = {2,3,6,7};
    for (auto x : s.combinationSum(can, 7))
    {
        for (auto y : x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}

//() ) ) ()