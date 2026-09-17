/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母


进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution242 {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) {
            return false;
        }
        if (n == 0) {
            return true;
        }

        vector<int> mp(26, 0);

        for (int i = 0;i < n;i++) {
            mp[s[i] - 'a']++;
        }
        for (int j = 0;j < n;j++) {
            mp[t[j] - 'a']--;
            if (mp[t[j] - 'a'] < 0){
                return false;
            }
        }

        return true;

    }
};


//int main() {
//	Solution242 solution;
//	string s = "anagram";
//	string t = "nagaram";
//	bool result = solution.isAnagram(s, t);
//	cout << "Is \"" << t << "\" an anagram of \"" << s << "\"? " << (result ? "true" : "false") << endl; // Output: true
//	s = "rat";
//	t = "car";
//	result = solution.isAnagram(s, t);
//	cout << "Is \"" << t << "\" an anagram of \"" << s << "\"? " << (result ? "true" : "false") << endl; // Output: false
//	return 0;
//}