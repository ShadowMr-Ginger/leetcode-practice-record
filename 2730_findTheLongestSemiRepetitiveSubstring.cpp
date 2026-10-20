#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution2730 {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int left = 0;
        int last = -1; // 窗口内最近一对相邻相等字符的左端下标
        int ans = 1;
        // 1. 滑动窗口，保证窗口内至多一对相邻相等
        for (int i = 1;i < n;i++) {
            if (s[i] == s[i - 1]) {
                // 2. 已存在一对相等，左端收缩到上一对之后的第一个字符
                if (last != -1) {
                    left = last + 1;
                }
                last = i - 1;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

//int main() {
//	Solution2730 solution;
//	string s1 = "52233";
//	string s2 = "5494";
//	string s3 = "1111111";
//	cout << solution.longestSemiRepetitiveSubstring(s1) << endl; // 4
//	cout << solution.longestSemiRepetitiveSubstring(s2) << endl; // 4
//	cout << solution.longestSemiRepetitiveSubstring(s3) << endl; // 2
//	return 0;
//}
