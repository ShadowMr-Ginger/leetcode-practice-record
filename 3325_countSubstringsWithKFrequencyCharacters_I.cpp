#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution3325 {
public:
    long long numberOfSubstrings(string s, int k) {
        int cnt[26] = {0};
        int left = 0;
        long long ans = 0;
        int n = s.size();
        // 1. 滑动窗口，保证窗口内每种字符出现次数都小于 k
        for (int right = 0;right < n;right++) {
            cnt[s[right] - 'a']++;
            // 2. 新字符达到 k 次，收缩左边界直到其次数降回 k-1
            while (cnt[s[right] - 'a'] >= k) {
                cnt[s[left] - 'a']--;
                left++;
            }
            // 3. 以 right 结尾且合法的子串个数
            ans += right - left + 1;
        }
        return ans;
    }
};

//int main() {
//	Solution3325 solution;
//	cout << solution.numberOfSubstrings("abacb", 2) << endl;   // 4
//	cout << solution.numberOfSubstrings("abcde", 1) << endl;   // 0
//	return 0;
//}
