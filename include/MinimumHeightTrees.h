#include <queue>
#include <vector>

using std::queue;
using std::vector;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{
	if (n == 0) return {};
	if (n == 1) return {0};
	if (n == 2) return {0, 1};

	queue<int> q;
	vector<int> ans;	// answer
	vector<int> degree(n, 0);
	vector<vector<int>> graph(n);

	for (const vector<int>& edge : edges)
	{
		int first = edge[0];
		int second= edge[1];
		
		graph[first].push_back(second);
		degree[first]++;

		graph[second].push_back(first);
		degree[second]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (degree[i] == 1)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cnt = q.size();
		ans.clear();

		while (cnt--)
		{
			int leaf = q.front();
			q.pop();
			ans.push_back(leaf);
			for (int i = 0; i < graph[leaf].size(); i++)
			{
				degree[graph[leaf][i]]--;
				if (degree[graph[leaf][i]] == 1)
				{
					q.push(graph[leaf][i]);
				}
			}

		}
	}
	return ans;
}