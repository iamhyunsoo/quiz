#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

#include <GameofLife.h>
int main()
{
    vector<vector<int>> vec = {{0,1,0},{0,0,1},{1,1,1}, {0,0,0}};
    gameOfLife(vec);
    for (int i = 0; i < vec.size(); i++)
    {   
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
        }
        cout << endl;
    }
}
