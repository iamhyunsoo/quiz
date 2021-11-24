#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

#include "GeneralizedAbbreviation.h"


#include <iomanip>

int main()
{
	double BTC = 31901.19;
	double ETH = 1901.54;
	double DOGE = 0.179733;

	std::cout << "Enter amount in cryptocurrency: ";

	double amt{ 0 };
	std::cin >> amt;


	std::cout << fixed << setprecision(2) << amt << " BTC in USD: $" << BTC * amt << std::endl;
	std::cout << fixed << setprecision(2) << amt << " ETH in USD: $"  << ETH * amt << std::endl;
	std::cout << fixed << setprecision(2) << amt << " DOGE in USD: $" << DOGE * amt << std::endl;
	return 0;
}