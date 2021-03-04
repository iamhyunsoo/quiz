#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    static string intToRoman(int num) 
    {
    string number = to_string(num);
    unordered_map <char, vector<string>> m 
    {
        {'0', {"", "", "", ""}},
        {'1', {"I", "X", "C", "M"}},
        {'2', {"II", "XX", "CC", "MM"}},
        {'3', {"III", "XXX", "CCC", "MMM"}},
        {'4', {"IV", "XL", "CD"}},
        {'5', {"V", "L", "D"}},
        {'6', {"VI", "LX", "DC"}},
        {'7', {"VII", "LXX", "DCC"}},
        {'8', {"VIII", "LXXX", "DCCC"}},
        {'9', {"IX", "XC", "CM"}}
    };
    
    string roman;
    int length = number.size()-1;
    for(const char& c : number)
        roman += m[c][length--];
    
    return roman;
    }
};