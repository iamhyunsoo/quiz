std::string alphabetBoardPath(std::string target) 
{
	std::string ret;
	int currX{ 0 };
	int currY{ 0 };
	int tempX{ 0 };
	int tempY{ 0 };
	for (char const& c : target)
	{
		tempX = (c - 'a') % 5;
		tempY = (c - 'a') / 5;

		ret += std::string(std::max(0, currY - tempY), 'U');
		ret += std::string(std::max(0, tempX - currX), 'R');
		ret += std::string(std::max(0, currX - tempX), 'L');
		ret += std::string(std::max(0, tempY - currY), 'D');
		ret += '!';

		currX = tempX;
		currY = tempY;
	}
	return ret;
}
