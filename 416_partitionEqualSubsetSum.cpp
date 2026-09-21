#include <iostream>
#include <vector>

using namespace std;

class Solution416 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        // 总和为奇数时无法分成两个和相等的子集
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        // dp[j] 表示能否从 nums 中选出若干个数，使其和恰好为 j
        vector<char> dp(target + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            // 逆序枚举容量，保证每个数最多被使用一次
            for (int j = target;j >= num;j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

//int main() {
//	Solution416 solution;
//	vector<int> nums = {1, 5, 11, 5};
//	cout << solution.canPartition(nums) << endl;
//	return 0;
//}
