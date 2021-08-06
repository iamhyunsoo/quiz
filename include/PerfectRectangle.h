
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
bool isRectangleCover(std::vector<std::vector<int>>& rectangles)
{
	int x1 = INT_MAX;
	int y1 = INT_MAX;
	int x2 = INT_MIN;
	int y2 = INT_MIN;
	int size = 0;
	std::unordered_set<std::string> s;

	for (auto const& rec : rectangles)
	{
		x1 = std::min(x1, rec[0]);
		y1 = std::min(y1, rec[1]);
		x2 = std::max(x2, rec[2]);
		y2 = std::max(y2, rec[3]);
		size += (rec[2] - rec[0]) * (rec[3] - rec[1]);

		std::string lb = std::to_string(rec[0]) + "-" + std::to_string(rec[1]);
		std::string lt = std::to_string(rec[0]) + "-" + std::to_string(rec[3]);
		std::string rb = std::to_string(rec[2]) + "-" + std::to_string(rec[1]);
		std::string rt = std::to_string(rec[2]) + "-" + std::to_string(rec[3]);

		if (s.find(lb) == s.end())
		{
			s.insert(lb);
		}
		else
		{
			s.erase(lb);
		}

		if (s.find(lt) == s.end())
		{
			s.insert(lt);
		}
		else
		{
			s.erase(lt);
		}

		if (s.find(rb) == s.end())
		{
			s.insert(rb);
		}
		else
		{
			s.erase(rb);
		}

		if (s.find(rt) == s.end())
		{
			s.insert(rt);
		}
		else
		{
			s.erase(rt);
		}
	}
	if (s.size() != 4 ||
		s.find(std::to_string(x1) + "-" + std::to_string(y1)) == s.end() ||
		s.find(std::to_string(x1) + "-" + std::to_string(y2)) == s.end() ||
		s.find(std::to_string(x2) + "-" + std::to_string(y1)) == s.end() ||
		s.find(std::to_string(x2) + "-" + std::to_string(y2)) == s.end())
	{
		return false;
	}

	return size == (x2 - x1) * (y2 - y1);
}
