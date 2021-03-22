
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "CombinationSum2.h"
#include "FirstMissingPositive.h"

using namespace std;

int main()
{
    Solution s;
    vector<int> can = {1,1,2,3,4};
    for (auto x : s.combinationSum2(can, 4))
    {
        for (auto y : x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
    vector<int> dd = {-10,-3,-100,-1000,-239,1};
    cout << FirstMissingPositive(dd) << endl;
}

//() ) ) ()