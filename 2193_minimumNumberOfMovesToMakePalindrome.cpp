#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Solution2193 {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0;i < n;i++) {
            cnt[s[i] - 'a']++;
        }
        int odd_cnt = 0;
        for (int i = 0;i < 26;i++) {
            if (cnt[i] % 2 == 1) odd_cnt++;
        }
        if (odd_cnt > 1) return -1; // 超过一个奇数字符无法回文

        int moves = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (s[left] == s[right]) { // 两端已匹配
                left++;
                right--;
                continue;
            }
            // 从右端找与 s[left] 相同的字符
            int k = right;
            while (k > left && s[k] != s[left]) k--;
            if (k == left) { // 当前字符是中心字符，先向内挪一步
                swap(s[left], s[left + 1]);
                moves++;
            } else {
                // 把 k 处的相同字符相邻交换到 right
                for (int i = k;i < right;i++) {
                    swap(s[i], s[i + 1]);
                    moves++;
                }
                left++;
                right--;
            }
        }
        return moves;
    }
};

//int main() {
//	Solution2193 sol;
//	cout << sol.minMovesToMakePalindrome("aabb") << endl;
//	cout << sol.minMovesToMakePalindrome("letelt") << endl;
//	return 0;
//}
