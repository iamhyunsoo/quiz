#include <string>
#include <vector>

//s consists of digits, '+', '-', '(', ')', and ' '  (NO MULTIPLICATION & DIVISION)
int calculate(std::string s)
{
	int ans {0};
	std::vector<int> op(2, 1);

	for (size_t i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c >= '0' && c <= '9')
		{
			int num {0};
			while (i < s.length() && s[i] >= '0' && s[i] <= '9')
			{
				num = (num * 10) + ( s[i++] - '0' );
			}
			i--;
			ans += ( num * op.back() );
			op.pop_back();
		}
		else if (c == ')')
		{	
			op.pop_back();
		}
		else if (c != ' ')
		{
			op.push_back(op.back() * (c == '-' ? -1 : 1));
		}
	}
	return ans;
}