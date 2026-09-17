#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution3762 {
public:
    // 维护动态中位数，支持加入/删除，查询所有数到中位数的绝对偏差和
    struct MedianTracker {
        multiset<long long> low, high;   // low 大根(存较小一半)，high 小根(存较大一半)
        long long sl = 0, sh = 0;        // 两半元素和

        void clear() { low.clear(); high.clear(); sl = sh = 0; }

        void rebalance() {
            // 保持 low 的大小等于 high 或比 high 多 1
            while ((long long)low.size() > (long long)high.size() + 1) {
                long long x = *low.rbegin();
                low.erase(prev(low.end())); sl -= x;
                high.insert(x); sh += x;
            }
            while ((long long)high.size() > (long long)low.size()) {
                long long x = *high.begin();
                high.erase(high.begin()); sh -= x;
                low.insert(x); sl += x;
            }
            // 保证 low 的最大值 <= high 的最小值
            while (!low.empty() && !high.empty() && *low.rbegin() > *high.begin()) {
                long long a = *low.rbegin(), b = *high.begin();
                low.erase(prev(low.end())); sl -= a;
                high.erase(high.begin()); sh -= b;
                low.insert(b); sl += b;
                high.insert(a); sh += a;
            }
        }

        void add(long long x) {
            if (low.empty() || x <= *low.rbegin()) { low.insert(x); sl += x; }
            else { high.insert(x); sh += x; }
            rebalance();
        }

        void remove(long long x) {
            auto it = low.find(x);
            if (it != low.end()) { low.erase(it); sl -= x; }
            else { it = high.find(x); high.erase(it); sh -= x; }
            rebalance();
        }

        long long sumAbs() {
            if (low.empty()) return 0;
            long long m = *low.rbegin();
            long long left = m * (long long)low.size() - sl;     // 左半到中位数
            long long right = sh - m * (long long)high.size();   // 右半到中位数
            return left + right;
        }
    };

    // 把 nums[l..r] 变成全相等（每次可对单个元素 ±1），代价为绝对偏差和
    long long minOperations(vector<int>& nums, int k) {
        int n = (int)nums.size();
        const long long INF = (long long)4e18;

        vector<long long> dpPrev(n + 1, INF), dp(n + 1, INF);
        dpPrev[0] = 0;

        // dp[j] = min_{i<j} dpPrev[i] + cost(i, j-1)，决策单调，用分治优化
        for (int t = 1;t <= k;t++) {
            solve(1, n, 0, n - 1, nums, dpPrev, dp);
            dpPrev = dp;
        }
        return dpPrev[n];
    }

private:
    MedianTracker mt;

    void solve(int jl, int jr, int optl, int optr, vector<int>& nums,
               vector<long long>& dpPrev, vector<long long>& dp) {
        if (jl > jr) return;
        int jm = (jl + jr) / 2;

        // 1. 建立区间 [optl, jm-1] 的中位数结构
        mt.clear();
        for (int i = optl;i <= jm - 1;i++) mt.add(nums[i]);

        // 2. 枚举决策 i，随 i 增大从左侧删除，维护 (i+1..jm-1) 的代价
        int limit = min(optr, jm - 1);
        int best = optl;
        long long bestVal = (long long)4e18;
        for (int i = optl;i <= limit;i++) {
            long long val = dpPrev[i] + mt.sumAbs();
            if (val < bestVal) { bestVal = val; best = i; }
            mt.remove(nums[i]); // 左端右移，窗口变为 (i+1..jm-1)
        }
        dp[jm] = bestVal;

        // 3. 递归左右，决策区间随 best 收缩
        solve(jl, jm - 1, optl, best, nums, dpPrev, dp);
        solve(jm + 1, jr, best, optr, nums, dpPrev, dp);
    }
};

//int main() {
//	Solution3762 sol;
//	vector<int> nums = {1, 4, 7, 10};
//	int k = 2;
//	cout << sol.minOperations(nums, k) << endl; // 例：分为 [1,4] 与 [7,10]，代价 3+3=6
//	return 0;
//}
