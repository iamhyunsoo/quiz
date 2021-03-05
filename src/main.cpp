#include "LongestCommonPrefix.h"

#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<std::string> vec = {"prex", "prebc", "prepare"};
    cout << Solution::longestCommonPrefix(vec)  << endl;
}