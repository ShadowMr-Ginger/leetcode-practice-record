#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution3957 {
public:
    long long maxSum(vector<int>& nums, int m) {
        int n = nums.size();
        if (m == 0) return 0;
        // 1. 前缀和数组
        vector<long long> pre_sum(n + 1, 0);
        for (int i = 1;i <= n;i++) pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        // 2. prev/cur 分别滚动表示选 j-1 个、j 个子数组的最优和
        vector<long long> prev(n + 1, 0), cur(n + 1, LLONG_MIN / 2);
        // 3. 按子数组个数递推
        for (int j = 1;j <= m;j++) {
            cur[0] = LLONG_MIN / 2;
            // 维护 max(prev[s] - pre_sum[s])，即以 i-1 结尾时的最佳前一段
            long long best = LLONG_MIN / 2;
            for (int i = 1;i <= n;i++) {
                // s = i-1 开始允许作为第 j 段的起点
                best = max(best, prev[i - 1] - pre_sum[i - 1]);
                // 不选 nums[i-1]，或让第 j 段恰好以 i-1 结尾
                cur[i] = max(cur[i - 1], best + pre_sum[i]);
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};

//int main() {
//	Solution3957 solution;
//	vector<int> nums = {1, 2, 3, 4, 5};
//	cout << solution.maxSum(nums, 2) << endl; // 15：[1,2,3] + [4,5]
//	vector<int> nums2 = {-1, 3, -2, 5, -1};
//	cout << solution.maxSum(nums2, 2) << endl; // 8：[3] + [5]
//	return 0;
//}
