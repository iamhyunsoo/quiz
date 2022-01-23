#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Node for convenience.
struct Node
{
	std::string mFrom;
	std::string mTo;
	double mRate;
	Node(std::string from, std::string to, double rate)
	{
		mFrom = from;
		mTo = to;
		mRate = rate;
	}
};

// Helper function using BFS with queues.
double Helper(std::string start, std::string end, std::unordered_map<std::string, std::unordered_map<std::string, double>>& rates)
{
	std::unordered_set<std::string> visited;
	std::queue<std::string> que;
	std::queue<double> qRate;
	double maxRate{ -1 };

	que.push(start);
	qRate.push(1.0);
	while (!que.empty())
	{
		std::string curCurrency = que.front();
		double curRate = qRate.front();
		que.pop();
		qRate.pop();

		if (visited.find(curCurrency) != visited.end()) { continue; }
		visited.insert(curCurrency);

		if (rates.find(curCurrency) != rates.end())
		{
			auto nextCurrencies = rates[curCurrency];
			for (auto const& p : nextCurrencies)
			{
				if (visited.find(p.first) == visited.end())
				{
					if (p.first == end)
					{
						maxRate = std::max(maxRate, curRate * p.second);
					}
					else
					{
						que.push(p.first);
						qRate.push(curRate * p.second);
					}
				}
			}
		}
	}
	return maxRate;
}

double MaxCurrency(std::vector<std::string> froms, std::vector<std::string> tos, std::vector<double> rates, std::string start, std::string end)
{
	std::unordered_map<std::string, std::unordered_map<std::string, double>> mp;
	std::vector<Node*> nodes;
	for (int i = 0; i < (int)froms.size(); i++)
	{
		nodes.push_back(new Node(froms[i], tos[i], rates[i]));
	}

	for (Node* node : nodes)
	{
		if (mp.find(node->mFrom) == mp.end())
		{
			mp[node->mFrom] = { {node->mTo, node->mRate} };
		}
		else
		{
			mp[node->mFrom].insert(std::pair<std::string, double>(node->mTo, node->mRate));
		}

		if (mp.find(node->mTo) == mp.end())
		{
			mp[node->mTo] = { {node->mFrom, 1 / node->mRate} };
		}
		else
		{
			mp[node->mTo].insert(std::pair<std::string, double>(node->mFrom, 1 / node->mRate));
		}
	}
	double answer = Helper(start, end, mp);

	for (auto& node : nodes)
	{
		delete node;
	}

	return answer;
}

int main() 
{
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(std::cin, line)) 
  {
    lines.push_back(line);
  }
  
  std::string strFx = lines[0];
  std::string start = lines[1];
  std::string end   = lines[2];
  
  auto parse = strFx | std::ranges::views::split(';')
                     | std::ranges::views::transform([](auto c){
                       return std::string_view(&*c.begin(), std::ranges::distance(c));
                     });
  
  std::vector<std::string> froms;
  std::vector<std::string> tos;
  std::vector<double> rates;
  
  std::vector<std::string> fxs(parse.begin(), parse.end());
  for (auto const& rate : fxs)
  {
    auto fx = rate | std::ranges::views::split(',')
                   | std::ranges::views::transform([](auto c){
                       return std::string_view(&*c.begin(), std::ranges::distance(c));
                   });
    
    std::vector<std::string> vecFx(fx.begin(), fx.end());
    froms.push_back(vecFx[0]);
    tos.push_back(vecFx[1]);
    rates.push_back(std::stod(vecFx[2]));
  }
  
  double ans = MaxCurrency(froms, tos, rates, start, end);
  if (ans == -1)  // Only for passing the test case. 
  {
    std::cout << "-1.0" << std::endl;
  }
  else
  {
    std::cout << ans << std::endl;
  }
  
  // cout << MaxCurrency({ "USD", "USD", "GBP" }, { "JPY", "GBP", "JPY" }, { 109, 0.71, 155 }, "USD", "JPY") << endl;
	// cout << MaxCurrency({ "USD", "USD", "GBP", "CAD", "CAD" }, { "GBP", "JPY", "JPY", "CNY", "KRW" }, { 0.7, 109, 155, 5.27, 921 }, "USD", "CNY") << endl;
}

/*
FX rates list:
	USD to JPY 1 to 109
	USD to GBP 1 to 0.71
	GBP to JPY 1 to 155
Original currency: USD
Target currency: JPY

Output:
Calculated the max target currency will can get.

For example:
USD to JPY -> 109
USD to GBP to JPY = 0.71 * 155 = 110.05 > 109

So, the max value will be 110.05
*/

/*
Test Input:
USD,GBP,0.7;USD,JPY,109;GBP,JPY,155;CAD,CNY,5.28;CAD,KRW,921
USD
CNY

Expected Output
-1.0
*/
