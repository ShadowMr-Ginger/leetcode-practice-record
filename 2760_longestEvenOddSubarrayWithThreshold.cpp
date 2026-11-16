#include <iostream>
#include <vector>
using namespace std;

class Solution2760 {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            // 起点必须是不超过 threshold 的偶数
            if (nums[i] > threshold || nums[i] % 2 != 0) {
                i++;
                continue;
            }
            // 从合法起点向右扩展，要求奇偶交替且都不超过 threshold
            int j = i + 1;
            while (j < n && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                j++;
            }
            ans = max(ans, j - i);
            // 跳过已处理区间
            i = j;
        }
        return ans;
    }
};

//int main() {
//	Solution2760 sol;
//	vector<int> nums = {3, 2, 5, 4};
//	cout << sol.longestAlternatingSubarray(nums, 5) << endl;
//	vector<int> nums2 = {1, 2};
//	cout << sol.longestAlternatingSubarray(nums2, 2) << endl;
//	return 0;
//}
