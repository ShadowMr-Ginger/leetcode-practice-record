#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution583 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] 表示 word1 前 i 个字符与 word2 前 j 个字符的最长公共子序列长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1;i <= m;i++) {
            for (int j = 1;j <= n;j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 最少删除次数 = 两串总长 - 2 * 最长公共子序列长度
        return m + n - 2 * dp[m][n];
    }
};

//int main() {
//	Solution583 solution;
//	cout << solution.minDistance("sea", "eat") << endl;
//	cout << solution.minDistance("leetcode", "etco") << endl;
//	return 0;
//}
