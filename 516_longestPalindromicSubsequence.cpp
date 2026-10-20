#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution516 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        // dp[i][j] 表示子串 s[i..j] 的最长回文子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0;i < n;i++) {
            dp[i][i] = 1;
        }

        // 按区间长度从小到大转移
        for (int len = 2;len <= n;len++) {
            for (int i = 0;i + len - 1 < n;i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

//int main() {
//	Solution516 solution;
//	cout << solution.longestPalindromeSubseq("bbbab") << endl;
//	cout << solution.longestPalindromeSubseq("cbbd") << endl;
//	return 0;
//}
