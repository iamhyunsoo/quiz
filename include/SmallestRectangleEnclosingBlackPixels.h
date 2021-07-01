#include <algorithm>
#include <vector>

class Solution 
{
public:
    int minArea(std::vector<std::vector<char>>& image, int x, int y) 
	{
		int up = x;
		int down = x;
		int left = y;
		int right = y;
		help(image, x, y, up, down, left, right);
		return (down - up + 1) * (right - left + 1);
    }

private:
	void help(std::vector<std::vector<char>>& image, int x, int y, int& up, int& down, int& left, int& right)
	{
		if (x < 0 || x >= (int)image.size() || y < 0 || y >= (int)image[0].size() || image[x][y] != '1')
		{
			return;
		}

		image[x][y] = '#';		//dummy
		up = std::min(up, x);
		down = std::max(down, x);
		left = std::min(left, y);
		right = std::max(right, y);

		help(image, x - 1, y, up, down, left, right);
		help(image, x , y + 1, up, down, left, right);
		help(image, x + 1, y, up, down ,left, right);
		help(image, x, y - 1, up, down, left, right);
		
		return;
	}
};