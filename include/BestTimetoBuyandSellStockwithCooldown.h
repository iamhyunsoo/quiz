#include <algorithm>
#include <vector>

#define INT_MIN (-2100000000)
using std::vector;

int maxProfit(vector<int> &prices)
{
	int prevBuy {INT_MIN};
	int buy {INT_MIN};
	int prevSell {0};
	int sell {0};

	for (auto const& price : prices)
	{
		prevBuy = buy;
		buy = std::max( buy, prevSell - price );
		prevSell = sell;
		sell = std::max( sell, prevBuy + price );	//[2,10,0,5,16]
	}

	return sell;
}