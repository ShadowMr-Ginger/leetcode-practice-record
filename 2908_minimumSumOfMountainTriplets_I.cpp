#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution2908 {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // 直接枚举所有满足 i < j < k 的三元组
        for (int i = 0;i < n - 2;i++) {
            for (int j = i + 1;j < n - 1;j++) {
                for (int k = j + 1;k < n;k++) {
                    // nums[i] 和 nums[k] 必须同时小于 nums[j]
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        ans = min(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        // 不存在合法三元组时返回 -1
        return ans == INT_MAX ? -1 : ans;
    }
};

//int main() {
//	Solution2908 sol;
//	vector<int> nums = {8, 6, 1, 5, 3};
//	cout << sol.minimumSum(nums) << endl;
//	return 0;
//}
