#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> m;
    m.emplace(1,3);
    m.emplace(4,-3);
    m.emplace(3,6);
    m.emplace(5,-6);

    for (auto x : m)
    {
        cout << x.first << ", " << x.second << endl;
    }
}
