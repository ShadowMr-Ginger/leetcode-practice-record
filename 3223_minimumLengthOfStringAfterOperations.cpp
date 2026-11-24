#include <iostream>
#include <string>
using namespace std;

class Solution3223 {
public:
    int minimumLength(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++; // 统计每个字符出现次数
        int ans = 0;
        // 1. 同一字符每次操作删左右各一个，等价于成对减少
        // 2. 数量小于 3 无法操作，奇数剩 1，偶数剩 2
        for (int i = 0;i < 26;i++) {
            if (cnt[i] == 0) continue;
            if (cnt[i] < 3) ans += cnt[i];
            else if (cnt[i] % 2 == 1) ans += 1;
            else ans += 2;
        }
        return ans;
    }
};

//int main() {
//	Solution3223 sol;
//	cout << sol.minimumLength("abaacbcbb") << endl;
//	cout << sol.minimumLength("aa") << endl;
//	return 0;
//}
