#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution3624 {
public:
    long long countK(long long n, int k) {
        if (n <= 0) return 0;
        // 1. 深度为 k-1 的所有 popcount 候选值（popcount 最多 64）
        vector<int> cand;
        for (int v = 1;v <= 64;v++) {
            if (depth(v) == k - 1) cand.push_back(v);
        }
        // 2. n 的二进制位，高位在前
        string bits;
        for (long long x = n;x;x >>= 1) bits.push_back(char('0' + (x & 1)));
        reverse(bits.begin(), bits.end());
        // 3. 对每个候选 popcount 值做数位 DP 并累加
        long long ans = 0;
        for (int v : cand) {
            memset(memo, -1, sizeof(memo));
            ans += solve(bits, 0, 1, 0, v);
        }
        return ans;
    }

private:
    long long memo[65][65];

    // m 的 popcount 深度：反复 popcount 到 1 所需的次数
    int depth(int x) {
        int d = 0;
        while (x != 1) {
            x = __builtin_popcount(x);
            d++;
        }
        return d;
    }

    // 统计 [0, n] 中 popcount 恰好为 v 的数（v>=1 时即 [1, n]）
    long long solve(const string& b, int pos, int tight, int ones, int v) {
        if (ones > v) return 0; // 剪枝
        if (pos == (int)b.size()) return ones == v ? 1 : 0;
        if (!tight && memo[pos][ones] != -1) return memo[pos][ones];
        int up = tight ? b[pos] - '0' : 1;
        long long res = 0;
        for (int d = 0;d <= up;d++) {
            res += solve(b, pos + 1, tight && d == up, ones + d, v);
        }
        if (!tight) memo[pos][ones] = res;
        return res;
    }
};

//int main() {
//	Solution3624 sol;
//	cout << sol.countK(10, 1) << endl; // 3：2 4 8
//	cout << sol.countK(10, 2) << endl; // 5：3 5 6 9 10
//	return 0;
//}
