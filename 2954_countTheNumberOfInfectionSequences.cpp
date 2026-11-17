#include <iostream>
#include <vector>
using namespace std;

class Solution2954 {
public:
    int countInfectionSequences(int n, vector<int>& sick) {
        const int MOD = 1000000007;
        // 1. 预处理阶乘和阶乘逆元，用于组合数计算
        vector<long long> fact(n + 1), inv_fact(n + 1);
        fact[0] = 1;
        for (int i = 1;i <= n;i++) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[n] = qpow(fact[n], MOD - 2);
        for (int i = n;i >= 1;i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;

        long long ans = 1;
        int total = 0;
        int m = sick.size();
        int prev = -1; // 上一个感染位置，-1 表示左边没有感染源
        // 2. 遍历每段连续健康区间（循环末尾补最后一段）
        for (int i = 0;i <= m;i++) {
            int boundary = (i < m) ? sick[i] : n;
            int len = boundary - prev - 1;
            if (len > 0) {
                total += len;
                ans = ans * inv_fact[len] % MOD;
                // 中间段左右都有感染源，段内每个位置可从左/右被感染
                if (prev != -1 && i < m) ans = ans * qpow(2, len - 1) % MOD;
            }
            prev = boundary;
        }
        // 3. 乘上各段感染顺序交错合并的方案数
        ans = ans * fact[total] % MOD;
        return (int)ans;
    }
private:
    long long qpow(long long a, long long b) {
        long long res = 1;
        a %= 1000000007;
        while (b > 0) {
            if (b & 1) res = res * a % 1000000007;
            a = a * a % 1000000007;
            b >>= 1;
        }
        return res;
    }
};

//int main() {
//	Solution2954 sol;
//	vector<int> sick1 = {1};
//	cout << sol.countInfectionSequences(5, sick1) << endl; // 4
//	vector<int> sick2 = {0, 4};
//	cout << sol.countInfectionSequences(5, sick2) << endl; // 4
//	vector<int> sick3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	cout << sol.countInfectionSequences(11, sick3) << endl; // 1
//	return 0;
//}
