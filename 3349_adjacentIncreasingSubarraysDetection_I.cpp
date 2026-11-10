#include <iostream>
#include <vector>
using namespace std;

class Solution3349 {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // 记录以 i 结尾的严格递增连续段长度
        vector<int> inc_len(n, 1);
        for (int i = 1;i < n;i++) {
            if (nums[i] > nums[i - 1]) {
                inc_len[i] = inc_len[i - 1] + 1;
            }
        }
        // 枚举一对相邻长度 k 子数组的起点 i 和 i+k
        for (int i = 0;i + 2 * k <= n;i++) {
            if (inc_len[i + k - 1] >= k && inc_len[i + 2 * k - 1] >= k) {
                return true;
            }
        }
        return false;
    }
};

//int main() {
//	Solution3349 sol;
//	vector<int> nums = {2,5,7,8,9,2,3,4,3,2};
//	cout << (sol.hasIncreasingSubarrays(nums, 3) ? "true" : "false") << endl;
//}
