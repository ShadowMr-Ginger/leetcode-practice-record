/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。



示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true


提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*

这是我自己做的哈希表做法。

Leetcode上过关，但是效率不够快。
对于这道题，既然字符都是小写字母，那么可以直接用一个长度为26的数组来统计字符出现次数，这样会更快。

*/

class Solution383 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 边界保护
        int n = ransomNote.length();
        int m = magazine.length();
        if (n > m) {
            return false;
        }
        if (n == 0) {
            return true;
        }

        // 记录magazine中字符
        unordered_map<char, int> dict;
        for (int i = 0;i < m;i++) {
            dict[magazine[i]]++;
        }

        // 对比ransomNote
        bool concluded = true;
        for (int j = 0;j < n;j++) {
            if (--dict[ransomNote[j]] < 0) {
                concluded = false;
                break;
            }
        }

        return concluded;

    }
};



/*

下面这个方法使用26字母的数组来统计字符出现次数，效率更高。

*/


class Solution383_PLUS {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 边界保护
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        // 使用长度为 26 的数组代替 unordered_map
        int count[26] = { 0 };

        // 统计 magazine 中每个字符的频次
        for (char c : magazine) {
            count[c - 'a']++;
        }

        // 消耗 ransomNote 中的字符
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) {
                return false; // 发现不够用，直接返回 false
            }
        }

        return true;
    }
};

//int main() {
//	Solution383_PLUS sol;
//	string ransomNote = "aa"; // Example input
//	string magazine = "aab"; // Example input
//	bool result = sol.canConstruct(ransomNote, magazine);
//	cout << "Can construct ransom note from magazine: " << (result ? "true" : "false") << endl;
//	return 0;
//}