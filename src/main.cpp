#include "PascalTriangle.h"
#include "PascalTriangle2.h"
#include <iostream>
using namespace std;
using std::vector;
int main()
{
    vector<int> vec(3, 1);
        cout << "[ ";
    for (auto u : vec)
    {
            cout << u << " ";
    }
        cout << " ]\n";

        cout << "[ ";
    for (auto u : getRow(3))
    {
            cout << u << " ";
    }
        cout << " ]\n";

    for (auto x : generate(5))
    {
        cout << "[ ";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << " ]\n";
    }
}
