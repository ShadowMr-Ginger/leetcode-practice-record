
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*
给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

测试用例保证答案唯一。



示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。


提示：

m == s.length
n == t.length
1 <= m, n <= 105
s 和 t 由英文字母组成


进阶：你能设计一个在 O(m + n) 时间内解决此问题的算法吗？

*/


// 滑动窗口法  但不够优化
class Solution76 {
public:
    string minWindow(string s, string t) {
        int n = s.length(); // 字符串s长度
        int m = t.length(); // 字符串t长度
        if (n < m || n == 0 || m == 0) {
            return "";
        }

        // 记录t中字符以及数量
        int charCount[128] = { 0 };
        bool charContain[128] = { false };
        for (int i = 0;i < m;i++) {
            charCount[t[i]]++;
            charContain[t[i]] = true;
        }

        // 滑动窗口  寻找最小覆盖子串
        int totalSurplus = m;
        int lp = 0;
        int minLen = 0;
        bool found = false;
        int best_lp = 0;
        int best_rp = 0;

        for (int rp = 0;rp < n;rp++) {
            if (!charContain[s[rp]]) {
                continue;
            }
            charCount[s[rp]]--;
            if (charCount[s[rp]] >= 0) {
                totalSurplus--;
            }
            // 满足覆盖子串要求时
            while (!totalSurplus) {
                while (!charContain[s[lp]] && lp<=rp) {
                    lp++;
                }
                if (!found) {
                    minLen = rp - lp + 1;
                    best_lp = lp;
                    best_rp = rp;
                    found = true;
                }
                if (found && minLen > rp - lp + 1) {
                    minLen = rp - lp + 1;
                    best_lp = lp;
                    best_rp = rp;
                }

                charCount[s[lp]]++;
                if (charCount[s[lp]] > 0) {
                    totalSurplus++;
                }
                lp++;
                if (lp >= rp) {
                    break;
                }
            }
        }

        string res = "";
        if (found) {
            res = s.substr(best_lp, minLen);
        }
        
        return res;

    }
};


// AI生成的优化版本，效率更高。
class Solution76_PLUS {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m || n == 0 || m == 0) return "";

        int charCount[128] = { 0 };
        for (char c : t) charCount[c]++;

        int totalSurplus = m; // 还需要匹配的字符数
        int lp = 0, minLen = INT_MAX, best_lp = 0;

        for (int rp = 0; rp < n; rp++) {
            // 1. 右指针字符入窗
            // 只有当 charCount > 0 时，说明是目标字符且还需要，才减少 surplus
            if (charCount[s[rp]] > 0) {
                totalSurplus--;
            }
            charCount[s[rp]]--; // 无论是否为目标字符，都消耗掉（非目标字符会变成 -1）

            // 2. 满足覆盖条件时，尝试收缩左边界
            while (totalSurplus == 0) {
                // 更新最优解
                if (rp - lp + 1 < minLen) {
                    minLen = rp - lp + 1;
                    best_lp = lp;
                }

                // 左指针字符出窗
                charCount[s[lp]]++;
                // *** *** 如果出窗后 charCount > 0，说明把一个必需的目标字符移出了窗口
                if (charCount[s[lp]] > 0) {
                    totalSurplus++;
                }
                lp++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(best_lp, minLen);
    }
};


//int main() {
//	Solution76_PLUS solution;
//	string s = "abc";
//	string t = "b";
//	string result = solution.minWindow(s, t);
//	cout << "The minimum window substring is: " << result << endl; // Output: "BANC"
//	return 0;
//}