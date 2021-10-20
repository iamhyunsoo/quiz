#include <vector>
#include <algorithm>

int minCostClimbingStairs(std::vector<int>& cost) 
{
  int size = cost.size();
  int one = cost[0];
  int two = cost[1];
  if (size <= 2)
  {
    return std::min(one, two);
  }

  for (int i = 2; i < size; i++)
  {
    int tmp = cost[i] + std::min(one, two);
    one = two;
    two = tmp;
  }

  return std::min(one, two);
}
