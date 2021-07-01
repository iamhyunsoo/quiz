#include <algorithm>
#include <vector>

class Solution 
{
public:
    std::vector<int> numIslands2(int m, int n, std::vector<std::vector< int >>& positions) 
	{
		std::vector<int> ret;
		std::vector<int> roots(m * n, -1);
		const int dir[5] = {1, 0, -1, 0, 1};

		int cnt {0};
		int curId {0};
		int tmpId {0};
		int x {0};
		int y {0};
		int p {0};
		int q {0};
		for (const auto& pos : positions)
		{
			curId = n * pos[0] + pos[1];
			if (roots[curId] != -1)
			{
				ret.push_back(cnt);
				continue;
			}

			roots[curId] = curId;
			cnt++;

			for (int i = 0; i < 4; i++)
			{
				x = pos[0] + dir[i];
				y = pos[1] + dir[i+1];
				tmpId = x * n + y;
				if (x < 0 || x >= m || y < 0 || y >= n || roots[tmpId] == -1)
				{
					continue;
				}
				 
				p = findRoot(roots, tmpId);
				q = findRoot(roots, curId);
				if (p != q)
				{
					roots[p] = q;
					--cnt;
				}
			}
			ret.push_back(cnt);
		}
		return ret;
    }

private:
	int findRoot(std::vector<int>& roots, int id)
	{
		return roots[id] == id ? id : findRoot(roots, roots[id]);
	}
};