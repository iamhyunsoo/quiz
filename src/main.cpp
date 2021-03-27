
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "GroupAnagrams.h"
using namespace std;
double ss(double x, int n)
{
    double ans = 1;
    int neg = n < 0 ? 1 : 0;
    while (n != 0)
    {
        if (n & 1)
        {
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;
}
int main()
{
    cout << ss(2, 10) <<endl;
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};

    for (auto x : groupAnagrams2(vec))
    {
        for (auto y :x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}
