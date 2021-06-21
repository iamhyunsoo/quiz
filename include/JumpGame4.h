#include <queue>
#include <unordered_map>
#include <vector>

int minJumps(std::vector<int> &arr)
{
	int n = arr.size();
	std::unordered_map<int, std::vector<int>> indicesOfValue;
	for (size_t i = 0; i < n; i++)
	{
		indicesOfValue[arr[i]].push_back(i);
	}

	std::queue<int> q{{0}};
	std::vector<bool> visited(n);
	visited[0] = true;

	int step{0};
	while (!q.empty())
	{
		for (int size = q.size(); size > 0; --size)
		{
			int i = q.front();
			q.pop();
			if (i == n - 1)
				return step;
			std::vector<int> &next = indicesOfValue[arr[i]];
			next.push_back(i - 1);
			next.push_back(i + 1);
			for (int j : next)
			{
				if (j >= 0 && j < n && !visited[j])
				{
					visited[j] = true;
					q.push(j);
				}
			}
			next.clear();
		}
		step++;
	}
	return 0;
}