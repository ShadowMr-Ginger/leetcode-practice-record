#include <iostream>
#include <vector>
using namespace std;

class Solution2572 {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD = 1000000007;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        // 预处理 1~30 的质因子掩码，-1 表示含有平方因子
        vector<int> mask(31, -1);
        mask[1] = 0;
        for (int x = 2;x <= 30;x++) {
            int m = 0;
            int y = x;
            bool ok = true;
            for (int i = 0;i < 10;i++) {
                int p = primes[i];
                if (y % (p * p) == 0) {
                    ok = false;
                    break;
                }
                if (y % p == 0) {
                    m |= (1 << i);
                    y /= p;
                }
            }
            if (ok) mask[x] = m;
        }

        // dp[s]：已处理数字的乘积质因子集合为 s 的方案数
        vector<int> dp(1 << 10, 0);
        dp[0] = 1;
        int cnt_one = 0;

        for (int x : nums) {
            if (x == 1) {
                cnt_one++;
                continue;
            }
            int m = mask[x];
            if (m == -1) continue;
            // 倒序保证每个数字只选一次
            for (int j = (1 << 10) - 1;j >= 0;j--) {
                if ((j & m) == 0) {
                    int nj = j | m;
                    dp[nj] = (dp[nj] + dp[j]) % MOD;
                }
            }
        }

        long long total = 0;
        for (int v : dp) total = (total + v) % MOD;

        long long p = 1;
        for (int i = 0;i < cnt_one;i++) p = p * 2 % MOD;

        // 去掉全空子集
        return (int)((total * p % MOD - 1 + MOD) % MOD);
    }
};

//int main() {
//	Solution2572 sol;
//	vector<int> nums = {1, 4};
//	cout << sol.squareFreeSubsets(nums) << endl;
//	return 0;
//}
