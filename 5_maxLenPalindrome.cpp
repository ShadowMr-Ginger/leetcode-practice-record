
/*
给你一个字符串 s，找到 s 中最长的 回文 子串。



示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
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


class Solution5 {
public:
	string longestPalindrome(string s) {
		// 在这里实现你的代码
		string ans = "";
		int len = 0;
		int st = 0;
		int n = s.length();
		if (n == 0) {
			return ans;
		}

		for (int i = 0;i < n;i++)
		{
			int current_len_odd = 1;
			int search_len = 1;
			while (i - search_len >= 0 && i + search_len < n) {
				if (s[i - search_len] == s[i + search_len]) {
					current_len_odd += 2;
					search_len++;
				}
				else {
					break;
				}
			}
			if (current_len_odd > len) {
				st = i - search_len + 1;
				len = current_len_odd;
			}
			int current_len_even = 0;
			search_len = 0;
			while (i - search_len - 1 >= 0 && i + search_len < n) {
				if (s[i - search_len - 1] == s[i + search_len]) {
					current_len_even += 2;
					search_len++;
				}
				else {
					break;
				}
			}
			if (current_len_even > len) {
				st = i - search_len;
				len = current_len_even;
			}
		}
		ans = s.substr(st, len);

		return ans;
	}
};


// AI 给的优化版本
class Solution5_PLUS {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) return s;

		int start = 0, maxLen = 1;

		for (int i = 0; i < n; ++i) {
			int len1 = expand(s, i, i);       // 奇数长度回文
			int len2 = expand(s, i, i + 1);   // 偶数长度回文
			int len = max(len1, len2);

			if (len > maxLen) {
				maxLen = len;
				start = i - (len - 1) / 2;    // 统一奇偶的起始位置公式
			}
		}

		return s.substr(start, maxLen);
	}

private:
	// 从中心向两边扩展，返回回文长度
	int expand(const string& s, int left, int right) {
		while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return right - left - 1;  // 退出时 left/right 已越界一格
	}
};


int main() {
	Solution5 s;
	string str = "cbbd";
	cout << s.longestPalindrome(str) << endl; // 输出 "bab" 或 "aba"
	return 0;
}