#include <vector>
using std::vector;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int sum {0};
    int remainGas {0};
    int start {0};

    for(int i = 0; i < gas.size(); i++)
    {
        sum += (gas[i] - cost[i]);
        remainGas += (gas[i] - cost[i]);
        if (remainGas < 0)
        {
            start = i + 1;
            remainGas = 0;
        }
    }
    return sum < 0 ? -1 : start;
}