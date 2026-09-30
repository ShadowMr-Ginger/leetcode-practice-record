#include <iostream>
#include <vector>

using namespace std;

class Solution2741 {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int full = (1 << n) - 1;
        long long mod = 1000000007;
        // dp[mask][j]：已选集合为 mask、末尾下标为 j 的合法排列数
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        // 1. 初始化：单个元素直接构成一个排列
        for (int j = 0;j < n;j++) {
            dp[1 << j][j] = 1;
        }
        // 2. 按集合从小到大转移
        for (int mask = 1;mask <= full;mask++) {
            for (int j = 0;j < n;j++) {
                if ((mask >> j & 1) == 0 || dp[mask][j] == 0) {
                    continue;
                }
                for (int k = 0;k < n;k++) {
                    if (mask >> k & 1) {
                        continue;
                    }
                    // 3. 末尾 j 与下一个 k 必须满足整除关系
                    if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                        int next_mask = mask | (1 << k);
                        dp[next_mask][k] = (dp[next_mask][k] + dp[mask][j]) % mod;
                    }
                }
            }
        }
        // 4. 汇总所有末位的完整集合答案
        int ans = 0;
        for (int j = 0;j < n;j++) {
            ans = (ans + dp[full][j]) % mod;
        }
        return ans;
    }
};

//int main() {
//	Solution2741 solution;
//	vector<int> nums1 = {2, 3, 6};
//	cout << solution.specialPerm(nums1) << endl;
//	vector<int> nums2 = {1, 4, 3};
//	cout << solution.specialPerm(nums2) << endl;
//	return 0;
//}
