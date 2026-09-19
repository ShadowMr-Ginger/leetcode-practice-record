#include <iostream>
#include <string>
using namespace std;

class Solution3298 {
public:
    long long validSubstringCount(string word1, string word2) {
        int need[26] = {0};
        for (char ch : word2) {
            need[ch - 'a']++;
        }

        int total = (int)word2.size();
        int n = (int)word1.size();
        if (total == 0) {
            return (long long)n * (n + 1) / 2;
        }

        int cnt[26] = {0};
        int formed = 0;
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            int c = word1[right] - 'a';
            // 只有仍缺该字符时，才增加已满足的需求数
            if (need[c] > 0 && cnt[c] < need[c]) {
                formed++;
            }
            cnt[c]++;

            // 收缩到当前 right 的最小合法左端点
            while (formed == total) {
                int l = word1[left] - 'a';
                if (need[l] > 0 && cnt[l] <= need[l]) {
                    formed--;
                }
                cnt[l]--;
                left++;
            }

            // left 就是当前 right 对应的合法起点数量
            ans += left;
        }
        return ans;
    }
};

//int main() {
//	Solution3298 sol;
//	cout << sol.validSubstringCount("bcca", "abc") << endl;
//	cout << sol.validSubstringCount("abcabc", "abc") << endl;
//	return 0;
//}
