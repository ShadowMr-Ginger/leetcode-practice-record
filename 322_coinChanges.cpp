/*


322. 零钱兑换

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。



示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0


提示：

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

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




// 较差的动态规划，f(k)表示凑成金额k所需的最少硬币个数，O(n*m)，其中n为金额，m为硬币种类数，Leetcode耗时2806ms，击败5.01%。
class Solution322_BAD {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        unordered_set<int> st;
        int n = coins.size();
        int max_coin_price = 0;
        for (int i = 0;i < n;i++) {
            if (coins[i] <= amount) {
                if (max_coin_price < coins[i]) {
                    max_coin_price = coins[i];
                }
                st.insert(coins[i]);
            }
        }

        vector<int> dp(amount + 1, 0);
        for (int i = 1;i <= amount;i++) {
            if (st.count(i)) {
                dp[i] = 1;
                continue;
            }
            for (int j = max(1, i - max_coin_price);j < i;j++) {
                if (dp[j] != 0 && st.count(i-j)) {
                    if (dp[i] == 0) {
                        dp[i] = dp[j] + 1;
                        continue;
                    }
                    else {
                        int current_coins = dp[j] + 1;
                        if (current_coins < dp[i]) {
                            dp[i] = current_coins;
                        }
                    }
                }
            }
        }


        if (dp[amount] > 0) {
            return dp[amount];
        }
        return -1;
    }
};


// AI优化方案如下：
// 极其优雅简洁的代码。

class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. 初始化 dp 数组，大小为 amount + 1
        // 初始值设为 amount + 1，因为就算全用 1 元硬币，最多也只需要 amount 个
        // 设为 amount + 1 相当于一个“无穷大”的哨兵，方便后续取 min
        vector<int> dp(amount + 1, amount + 1);

        // 2. 基础状态：凑出金额 0 需要 0 个硬币
        dp[0] = 0;

        // 3. 自底向上计算每一个金额的最少硬币数
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                // 只有当硬币面值小于等于当前目标金额时，才能使用
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 4. 如果 dp[amount] 依然是初始的哨兵值，说明凑不出来，返回 -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};



//
//int main() {
//	Solution322 solution;
//	vector<int> coins = {  2 , 5 };
//	int amount = 1;
//	int result = solution.coinChange(coins, amount);
//	cout << "Minimum coins needed: " << result << endl; // Output: 3
//	return 0;
//}