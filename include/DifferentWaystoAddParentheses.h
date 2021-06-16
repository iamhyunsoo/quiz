#include <cctype>
#include <string>
#include <vector>

std::vector<int> diffWaysToCompute(std::string expression)
{
	std::vector<int> ret;
	for (int i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (ispunct(c))
		{
			for (int const& x : diffWaysToCompute(expression.substr(0, i)))
			{
				for (int const& y : diffWaysToCompute(expression.substr(i+1)))
				{
					ret.push_back(c == '+' ? x + y : c == '-' ? x - y : x * y);
				}
			}
		}
	}
	return !ret.empty() ? ret : std::vector<int>{std::stoi(expression)};
}