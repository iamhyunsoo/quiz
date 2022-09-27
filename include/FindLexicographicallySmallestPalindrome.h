#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

/*
 * inputStr, represents the given string for the puzzle
 * Summary: Find the lexicographically smallest palindrome string
 *          longer than 1.
 */
std::string findPalindromeSubstring (std::string inputStr)
{
  // Write your code here
  if (inputStr.size() <= 1) return "X";
  std::vector<std::string> palins;
	for (size_t i =1 ; i < inputStr.size(); ++i)
	{
		int l = i - 1;
		int r = i + 1;
		if (inputStr[i] == inputStr[l]) --l;
		if (inputStr[i] == inputStr[r]) ++r;
		while (l >= 0 && r < inputStr.size())
		{
			if (inputStr[l] == inputStr[r])
			{
				--l;
				++r;
			}
			else
			{
        auto palindrom = inputStr.substr(l+1, (r- l - 1));
        if (palindrom.length() > 1)
        {
          palins.push_back(palindrom);
        }
				break;
			}
		}
		
	}
	if (palins.size())
	{
		std::sort(palins.begin(), palins.end());
    return palins[0];
	}
  return "X";
}

int main()
{
	//input for inputStr
	std::string inputStr;
	getline(std::cin,inputStr);
    
	std::cout << findPalindromeSubstring(inputStr);
	
  return 0;
}
