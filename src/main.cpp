
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "MergeInterval.h"
using namespace std;

int main()
{
       vector<vector<int> > mat {
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0 }
            };
    vector< vector<int> > vec = { {1,3}, {2,5}, };

    for (auto x : merge(vec))
    {
        for (auto y :x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}
