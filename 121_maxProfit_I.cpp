#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        // 数组长度
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        // 记录历史低位价格
        int historical_min = prices[0];
        // 计入历史最高利润
        int max_profit = 0;

        for (int i = 1;i < n;i++) {
            // 若当天卖，对比最高利润
            int today_profit = prices[i] - historical_min;
            max_profit = max(max_profit, today_profit);
            // 更新历史低位价格
            historical_min = min(historical_min, prices[i]);
        }

        return max_profit;
    }
};

//int main() {
//	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
//	Solution121 sol;
//	int profit = sol.maxProfit(prices);
//	cout << "Max profit: " << profit << endl;
//	return 0;
//}