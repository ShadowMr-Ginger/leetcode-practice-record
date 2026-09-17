/*

123. 买卖股票的最佳时机 III

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：

输入：prices = [1]
输出：0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <stack>
#include <array>
#include <numeric>
#include <queue>
using namespace std;


// 原做法：动态规划，空间复杂度 O(n)，时间复杂度 O(n)  但是遍历了4次，常数较大。

class Solution123 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // 先计算前缀最小和后缀最大
        vector<int> left_min(n, 0);
        vector<int> right_max(n, 0);
        left_min[0] = prices[0];
        right_max[n - 1] = prices[n - 1];
        for (int i = 1;i < n;i++) {
            if (prices[i] < left_min[i - 1]) {
                left_min[i] = prices[i];
            }
            else {
                left_min[i] = left_min[i - 1];
            }
            if (prices[n - i - 1] > right_max[n - i]) {
                right_max[n - i - 1] = prices[n - i - 1];
            }
            else {
                right_max[n - i - 1] = right_max[n - i];
            }
        }

        // 计算前缀单次交易收益最大值和后缀单词交易收益最大值。
        vector<int> max_prefix_profit(n, 0);
        vector<int> max_surfix_profit(n, 0);
        for (int i = 1;i < n; i++) {
            if (max_prefix_profit[i - 1] < prices[i] - left_min[i]) {
                max_prefix_profit[i] = prices[i] - left_min[i];
            }
            else {
                max_prefix_profit[i] = max_prefix_profit[i - 1];
            }
            if (max_surfix_profit[n - i] < right_max[n - i - 1] - prices[n - i - 1]) {
                max_surfix_profit[n - i - 1] = right_max[n - i - 1] - prices[n - i - 1];
            }
            else {
                max_surfix_profit[n - i - 1] = max_surfix_profit[n - i];
            }
        }
        int max_profit = 0;
        for (int i = 1;i < n; i++) {
            if (max_prefix_profit[i] + max_surfix_profit[i] > max_profit) {
                max_profit = max_prefix_profit[i] + max_surfix_profit[i];
            }
        }

        return max_profit;
    }
};

// 优化做法：动态规划，空间复杂度 O(1)，时间复杂度 O(n)  只遍历了一次，常数较小。
class Solution123_PLUS {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        // 四个状态变量
        int buy1 = -prices[0];  // 第一次买入后的利润（负数，表示支出）
        int sell1 = 0;          // 第一次卖出后的利润
        int buy2 = -prices[0];  // 第二次买入后的利润
        int sell2 = 0;          // 第二次卖出后的利润

        for (int i = 1; i < n; ++i) {
            // 第一次买入：要么之前已经买了，要么今天买入
            buy1 = max(buy1, -prices[i]);
            // 第一次卖出：要么之前已经卖了，要么今天卖出
            sell1 = max(sell1, buy1 + prices[i]);
            // 第二次买入：要么之前已经买了，要么今天买入（用第一次卖出的利润）
            buy2 = max(buy2, sell1 - prices[i]);
            // 第二次卖出：要么之前已经卖了，要么今天卖出
            sell2 = max(sell2, buy2 + prices[i]);
        }

        return sell2;
    }
};


//int main() {
//	Solution123 s;
//	vector<int> prices = { 8,3,6,2,8,8,8,4,2,0,7,2,9,4,9 };
//	cout << s.maxProfit(prices) << endl;
//	return 0;
//}