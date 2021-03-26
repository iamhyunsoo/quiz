
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "Permutation2.h"
using namespace std;

int main()
{
    Sol2 s;
    vector<int> can = {1,2,3,4};

    for (auto x : s.permuteUnique(can))
    {
        for (auto y :x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}
