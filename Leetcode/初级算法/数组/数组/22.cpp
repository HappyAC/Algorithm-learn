#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
//买卖股票的最佳时机 II

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1) return 0;

	bool first = true, buy = false;
	int profit = 0;
	int buy_price;

	vector<int>::iterator it = prices.begin();

	while (it != prices.end() - 1) {

		if (first) { 
			if (*it < *(it + 1)) { // first, if increase, buy it. if descrese ,do nothing
				//cout << "buy" << endl;
				buy_price = *it;
				buy = true;
			}
			first = false;
		}

		//bought, or last day and has bought, wait to sell (when price turn to decrease)
		if (buy && (*it > *(it + 1))) {
			//cout << "buy" << endl;
			profit += *it - buy_price;
			buy = false;
		}
		//not bought yet, wait to buy (when price turn to increase)
		if (!buy && *it < *(it + 1)) {
			//cout << "sell" << endl;
			buy_price = *it;
			buy = true;
		}
		it++;
	 }
	//last day
	if (buy) {
		profit += * it - buy_price;
	}

	return profit;
}

int main_22() {
	vector<int> prices = { 1,5 };
	//code
	cout << maxProfit(prices) << endl;
	system("pause");
	return 0;
}