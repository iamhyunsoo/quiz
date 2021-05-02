#include "PascalTriangle.h"
#include "PascalTriangle2.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using std::vector;
int main()
{
    string a = "sibal";
    string b = "vibal";
    cout << strcmp(a.c_str(), b.c_str()) << endl << endl; 

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
