/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。



示例 1：

输入：s = "egg", t = "add"

输出：true
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


// 利用长度128的数组来存储字符映射关系，避免使用哈希表，提高效率

class Solution205 {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m != n) {
            return false;
        }

        bool ans = true;

        int current_code1 = 0;
        vector<int> mp1(128, 0);
        int current_code2 = 0;
        vector<int> mp2(128, 0);
        for (int i = 0;i < m;i++) {
            int ct_1 = -1;
            int ct_2 = -1;
            if (!mp1[s[i]]) {
                current_code1++;
                mp1[s[i]] = current_code1;
            }
            ct_1 = mp1[s[i]];

            if (!mp2[t[i]]) {
                current_code2++;
                mp2[t[i]] = current_code2;
            }
            ct_2 = mp2[t[i]];

            if (ct_1 != ct_2) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};

//int main() {
//	Solution205 sol;
//	string s = "egg";
//	string t = "add";
//	bool result = sol.isIsomorphic(s, t);
//	cout << (result ? "true" : "false") << endl; // Output: true
//	return 0;
//}