/*

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。



示例 1：


输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true

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

class Solution97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s = s1.length();
        int t = s2.length();
        int r = s3.length();
        if (s + t != r) {
            return false;
        }
        vector<vector<bool>> dp(s + 1, vector<bool>(t + 1, 0));
        dp[0][0] = true;
        // 先把两个一维dp算好
        for (int i = 0;i < s;i++) {
            if (s3[i] == s1[i] && dp[i][0]) {
                dp[i + 1][0] = true;
            }
        }
        for (int j = 0;j < t;j++) {
            if (s3[j] == s2[j] && dp[0][j]) {
                dp[0][j + 1] = true;
            }
        }

        //算二维
        for (int i = 0;i < s;i++) {
            for (int j = 0;j < t;j++) {
                if (s3[i + j + 1] == s1[i] && dp[i][j + 1]) {
                    dp[i + 1][j + 1] = true;
                }
                if (s3[i + j + 1] == s2[j] && dp[i + 1][j]) {
                    dp[i + 1][j + 1] = true;
                }
            }
        }

        return dp[s][t];
    }
};


//int main() {
//	Solution97 s;
//	string s1 = "aabcc";
//	string s2 = "dbbca";
//	string s3 = "aadbbcbcac";
//	cout << s.isInterleave(s1, s2, s3) << endl;
//	return 0;
//}