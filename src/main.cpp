#include "twosum.h"

int main()
{
    vector<int> fs{3,2,4};
    vector<int> ans = Solution::twoSum(fs, 6);

    vector<double> fs2{4.3, 2.2, 5.5};
    vector<size_t> aa = TwoSum::proc<double>(fs2, 7.7);
    for (auto x : aa)
    {
        cout << x << ", ";
    }
    cout << "sibal" << endl;
}

