#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2218 {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // dp[j] 表示已处理的堆中一共取 j 枚硬币能获得的最大价值
        vector<int> dp(k + 1, 0);
        for (int i = 0;i < piles.size();i++) {
            int m = piles[i].size();
            // 1. 前缀和：取当前堆前 t 枚硬币的价值
            vector<int> prefix(m + 1, 0);
            for (int t = 0;t < m;t++) {
                prefix[t + 1] = prefix[t] + piles[i][t];
            }
            // 2. 分组背包：倒序枚举总枚数 j，再枚举从当前堆取 t 枚
            for (int j = k;j >= 0;j--) {
                int best = dp[j];
                for (int t = 1;t <= min(j, m);t++) {
                    best = max(best, dp[j - t] + prefix[t]);
                }
                dp[j] = best;
            }
        }
        return dp[k];
    }
};

//int main() {
//	vector<vector<int>> piles = {{1,100,3},{7,8,9}};
//	Solution2218 s;
//	cout << s.maxValueOfCoins(piles, 2) << endl;
//	vector<vector<int>> piles2 = {{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}};
//	cout << s.maxValueOfCoins(piles2, 7) << endl;
//	return 0;
//}
