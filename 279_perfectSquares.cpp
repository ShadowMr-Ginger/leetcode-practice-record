#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution279 {
public:
    int numSquares(int n) {
        // dp[i] 表示凑出 i 所需的最少完全平方数个数
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        // 1. 外层枚举目标值
        for (int i = 1;i <= n;i++) {
            // 2. 内层枚举最后选的平方数 j*j
            for (int j = 1;j * j <= i;j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

//int main() {
//	Solution279 solution;
//	cout << solution.numSquares(12) << endl;  // 输出 4
//	cout << solution.numSquares(13) << endl;  // 输出 2
//	return 0;
//}
