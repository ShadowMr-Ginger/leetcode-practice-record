
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出 : 3
解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
示例 2 :

    输入 : s = "bbbbb"
    输出 : 1
    解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3 :

    输入 : s = "pwwkew"
    输出 : 3
    解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


    提示：

    0 <= s.length <= 5 * 104
    s 由英文字母、数字、符号和空格组成
 */






 /*
 哈希表+滑动窗口

 这种方法在leetcode上大概耗时  20ms，
 没做到0ms的原因是使用了unordered_map来统计字符出现次数，效率不够高。
 题目中说s由英文字母、数字、符号和空格组成，所以可以直接用一个长度为128的数组来统计字符出现次数，这样会更快。
 
 */ 
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        // 处理极端情况
        int n = s.length();
        if (n <= 1) {
            return n;
        }

        // 定义字符集
        unordered_map<char, int> al_cnt;

        // 定义窗口左指针
        int lp = 0;

        // 定义子串长度
        int len = 0;

        // 定义最长子串长度
        int max_len = 0;

        // 移动右指针
        for (int rp = 0; rp < n;rp++) {
            al_cnt[s[rp]]++;
            len++;
            //若出现重复，右移左指针直到消除重复
            while (al_cnt[s[rp]] > 1) {
                al_cnt[s[lp++]]--;
                len--;
            }
            if (len > max_len) {
                max_len = len;
            }
        }

        // 返回值
        return max_len;
    }
};





/*

这是AI生成的代码，使用数组代替unordered_map，效率更高。
在leetcode上耗时 0ms。

*/

class Solution3_PLUS {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n <= 1) return n;

        // 使用数组代替 unordered_map，ASCII 字符最多 128 个
        int charCount[128] = { 0 };

        int lp = 0;
        int max_len = 0;

        for (int rp = 0; rp < n; rp++) {
            // 右指针字符入窗
            charCount[s[rp]]++;

            // 如果当前字符数量大于 1，说明有重复，收缩左边界
            while (charCount[s[rp]] > 1) {
                charCount[s[lp]]--;
                lp++;
            }

            // 直接用指针计算当前窗口长度，无需维护额外的 len 变量
            max_len = max(max_len, rp - lp + 1);
        }

        return max_len;
    }
};

//
//int main() {
//	Solution3 sol;
//	string s = "abcabcbb";
//	cout << "Length of longest substring without repeating characters: " << sol.lengthOfLongestSubstring(s) << endl;
//	Solution3_PLUS sol_plus;
//	cout << "Length of longest substring without repeating characters (optimized): " << sol_plus.lengthOfLongestSubstring(s) << endl;
//	return 0;
//}