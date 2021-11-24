#include <algorithm>
#include <vector>

int deleteAndEarn(vector<int>& nums)
{
  int n = 10001;
  std::vector<int> table(n, 0);

  for (auto const& num : nums)
  {
    table[num] += num;
  }

  int includeI = 0;
  int excludeI = 0;
  for (int i = 0 ; i < n ; i++)
  {
    int tmpIncludeI = excludeI + table[i];
    int tmpExcludeI = std::max(includeI, excludeI);
    includeI = tmpIncludeI;
    excludeI = tmpExcludeI;
  }

  return std::max(includeI, excludeI);
}
