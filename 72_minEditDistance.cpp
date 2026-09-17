/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符


示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')


提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

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


class Solution72 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 从word1变为空：
        for (int i = 1;i < m + 1;i++) {
            dp[i][0] = i;
        }
        // 从空变为word2：
        for (int j = 1;j < n + 1;j++) {
            dp[0][j] = j;
        }

        // 计算dp
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1;j < n + 1;j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[m][n];
    }
};

//
//int main() {
//	Solution72 s;
//	string word1 = "horse";
//	string word2 = "ros";
//	cout << s.minDistance(word1, word2) << endl; // 输出 3
//	return 0;
//}