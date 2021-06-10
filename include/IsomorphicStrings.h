#include <string>

bool isIsomorphic(std::string s, std::string t) 
{
    char m1[128] = {0};
    char m2[128] = {0};
    for (size_t i = 0; i < s.length(); i++)
    {
	if (m1[s[i]] != m2[t[i]])
	    return false;
	
	m1[s[i]] = i+1;
	m2[t[i]] = i+1;
    }
    return true;
}