#include <algorithm>
#include <string>

std::string addStrings(std::string num1, std::string num2) 
{
	int len1 = num1.length() - 1;
	int len2 = num2.length() - 1;
	int carry = 0;
	std::string ret = "";
	while (len1 >= 0 || len2 >= 0 || carry)
	{
		long sum{ 0 };
		if (len1 >= 0)
		{
			sum += num1[len1] - '0';
			len1--;
		}
		if (len2 >= 0)
		{
			sum += num2[len2] - '0';
			len2--;
		}
		sum += carry;
		carry = sum / 10;
		sum %= 10;
		ret += std::to_string(sum);
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}
