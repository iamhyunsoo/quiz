#include <string>
using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        if (s.size() == 0)
        {
            return "";
        }

        int start=0; int end=0;
        for (int i=0;i<s.size();i++)
        {
            int len1=PaliLength(i, i, s);
            int len2=PaliLength(i, i+1, s);
            int len = std::max(len1, len2);
            if (len > end - start) 
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        if (start == end)                               //when string = "ac";
        {                                               //This will return "a", not "c";
            return s.substr(0,1);                       //This is just for some criteria on leetcode, so doesn't have to exist;
        }

        return s.substr(start, end - start + 1);
    }

    static int PaliLength(int left, int right, string s)
    {
        int L = left; 
        int R = right;

        while ( L >= 0 && R<s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }//
        return R - L - 1;
    }
};
