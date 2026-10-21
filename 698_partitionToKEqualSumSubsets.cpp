#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution698 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0;i < n;i++) sum += nums[i];
        // 1. 总和必须能被 k 整除
        if (sum % k != 0) return false;
        target = sum / k;
        // 2. 从大到小排序，先放大数字更易剪枝
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target) return false;
        used.assign(n, false);
        return backtrack(nums, 0, 0, 0, k);
    }

private:
    int target;
    vector<bool> used;

    // cur_sum 为当前桶已装的和，count 为已装满的桶数
    bool backtrack(vector<int>& nums, int start, int cur_sum, int count, int k) {
        if (count == k) return true;
        // 当前桶装满，开一个新桶从头选
        if (cur_sum == target) {
            return backtrack(nums, 0, 0, count + 1, k);
        }
        for (int i = start;i < (int)nums.size();i++) {
            if (used[i]) continue;
            // 降序排列，超了就说明后面更小的也不用试了
            if (cur_sum + nums[i] > target) break;
            used[i] = true;
            if (backtrack(nums, i + 1, cur_sum + nums[i], count, k)) return true;
            used[i] = false;
        }
        return false;
    }
};

//int main() {
//	Solution698 s;
//	vector<int> nums = {4,3,2,3,5,2,1};
//	cout << boolalpha << s.canPartitionKSubsets(nums, 4) << endl;
//	vector<int> nums2 = {1,2,3,4};
//	cout << boolalpha << s.canPartitionKSubsets(nums2, 3) << endl;
//	return 0;
//}
