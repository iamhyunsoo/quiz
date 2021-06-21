#include <queue>
#include <vector>

int a(int n)
{
	int curr = 1;
	std::queue<int> queue;
	std::vector<int> sqrs;
	std::vector<int> numofSqrs(n, 0);
	for (int i = 1; i*i <= n; i++)
	{
		const int tmp = i*i;
		sqrs.push_back(tmp);
		queue.push(tmp);
		numofSqrs[tmp - 1] = 1;
	}
	while (!queue.empty())
	{
		curr++;
		auto size = queue.size();
		for (int i =0; i < size; i++)
		{
			auto tmp = queue.front();
			for (auto const& j : sqrs)
			{
				if (tmp + j == n)
				{
					return curr;
				}
				else if ((tmp + j) < n && !numofSqrs[tmp + j - 1])
				{
					numofSqrs[tmp+j-1] = curr;
					queue.push(tmp +j -1);
				}
				else if (tmp + j > n)
				{
					break;
				}
			}
			queue.pop();
		}
	}
	return 0;
}

int numSquares(int n)
{
	if (!n) return 0;

	std::queue<int> q;
	std::vector<int> sqrs;
	std::vector<int> numsOfSqrs(n, 0);
	for (int i = 1; i*i <= n; i++)
	{
		sqrs.push_back(i*i);
		numsOfSqrs[i*i-1] = 1;
		q.push(i*i);
	}
	if (sqrs.back() == n) return 1;
	
	int curr = 1;
	while (!q.empty())
	{
		curr++;
		size_t size = q.size();
		for (size_t i = 0; i < size; i++)
		{
			auto tmp = q.front();
			for(auto const& j : sqrs)
			{
				if (tmp + j == n)
				{
					return curr;
				}
				else if ((tmp + j < n) && !numsOfSqrs[tmp + j - 1])
				{
					numsOfSqrs[tmp + j - 1] = curr;
					q.push(tmp + j);
				}
				else if (tmp + j > n)
				{
					break;
				}
			}
			q.pop();
		}
	}
	return 0;
}