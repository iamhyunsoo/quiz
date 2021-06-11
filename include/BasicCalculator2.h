#include <string>
#include <sstream>

//s consists of digits, '+', '-', '*', '/', and ' ' (NO PARENTHESIS)
int calculate(std::string s) 
{
	std::string newString {""};
	if (s[0] != '-')
	{
		newString = '+' + s + '+';
	}
	else
	{
		newString = s + '+';
	}
	std::istringstream st(newString);

	long ans {0};
	long tmp {0};
	long num {0};
	char op {' '};
	while (st >> op)
	{
		if (op == '+' || op == '-')
		{
			ans += tmp;
			st >> tmp;
			tmp *= 44 - op;  // + : 43 , - : 45 in ascii
		}
		else
		{
			st >> num;
			if (op == '*')
			{
				tmp *= num;
			}
			else
			{
				tmp /= num;
			}
		}
	}
	return ans;
}