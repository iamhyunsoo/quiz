
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "IsValid.h"

using namespace std;

int main()
{
    std::string a = "{}[][";

    cout << Solution::isValid(a) << endl;
}