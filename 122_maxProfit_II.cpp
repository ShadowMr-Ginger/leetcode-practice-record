#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        // 记录利润
        int max_profit = 0;

        for (int i = 0;i < n - 1;i++) {
            // 明天的涨跌
            int delta = prices[i + 1] - prices[i];
            if (delta > 0) {
                // 只赚涨的部分
                max_profit += delta;
            };
        }

        return max_profit;

    }
};

//int main() {
//	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
//	Solution122 sol;
//	int profit = sol.maxProfit(prices);
//	cout << "Max profit: " << profit << endl;
//	return 0;
//}