/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。具体来说：

pattern 中的每个字母都 恰好 映射到 s 中的一个唯一单词。
s 中的每个唯一单词都 恰好 映射到 pattern 中的一个字母。
没有两个字母映射到同一个单词，也没有两个单词映射到同一个字母。


示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution290 {
public:
    bool wordPattern(string pattern, string s) {
        int len = s.length();
        int n = pattern.length();

        unordered_map<string, char> mp1;
        unordered_map<char, string> mp2;
        string word;
        int start_p = 0;
        int pattern_point = 0;

        bool ans = true;

        s += " ";
        len++;

        for (int i = 1;i < len;i++) {
            if (s[i] == ' ') {
                word = s.substr(start_p, i - start_p);
                char p = pattern[pattern_point];
                if (mp1.count(word)) {
                    if (pattern_point >= n || !mp2.count(p) || mp1[word] != p) {
                        return false;
                    }
                }
                else {
                    if (mp2.count(p)) {
                        return false;
                    }
                }
                mp1[word] = p;
                mp2[p] = word;
                pattern_point++;

                start_p = i + 1;
            }
        }

        if (pattern_point != n) {
            return false;
        }

        return ans;
    }
};




//int main() {
//	Solution290 solution;
//	string pattern = "abba";
//	string s = "dog cat cat dog";
//	bool result = solution.wordPattern(pattern, s);
//	cout << (result ? "true" : "false") << endl; // 输出: true
//	pattern = "abba";
//	s = "dog cat cat fish";
//	result = solution.wordPattern(pattern, s);
//	cout << (result ? "true" : "false") << endl; // 输出: false
//	pattern = "aaaa";
//	s = "dog cat cat dog";
//	result = solution.wordPattern(pattern, s);
//	cout << (result ? "true" : "false") << endl; // 输出: false
//	return 0;
//}