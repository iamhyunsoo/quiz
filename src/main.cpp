#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

#include <GeneralizedAbbreviation.h>
#include <NumberofIslands2.h>
int main()
{
    for (auto const& word : generateAbbreviations("word"))
    {
        cout << word << endl;
    }

}