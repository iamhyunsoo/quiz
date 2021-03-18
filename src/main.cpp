
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "FindFirstLastInArray.h"

using namespace std;

int main()
{
    std::vector<int> df = {1, 2, 3, 4, 6, 7, 7, 7, 9};
    for (auto x : searchRange(df, 7))
    {
        std::cout << x << std::endl;
    }
}

//() ) ) ()