#include <string>

bool isAnagram(std::string s, std::string t)
{
	const int len = s.length();
	if (len != t.length())
		return false;

	int cnts[26] = {0};
	for (int i = 0; i < len; i++)
	{
		cnts[s[i] - 'a']++;
		cnts[t[i] - 'a']--;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (cnts[i])
			return false;
	}
	return true;
}