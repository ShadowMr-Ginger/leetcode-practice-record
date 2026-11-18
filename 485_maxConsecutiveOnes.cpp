#include <iostream>
#include <vector>
using namespace std;

class Solution485 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;  // 历史最长连续 1 个数
        int cur_count = 0;  // 当前连续 1 个数
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == 1) {
                // 1. 遇到 1，当前计数加一并更新最大值
                cur_count++;
                max_count = max(max_count, cur_count);
            } else {
                // 2. 遇到 0，当前连续被打断，重置计数
                cur_count = 0;
            }
        }
        return max_count;
    }
};

//int main() {
//	Solution485 s;
//	vector<int> nums1 = {1, 1, 0, 1, 1, 1};
//	vector<int> nums2 = {1, 0, 1, 1, 0, 1};
//	cout << s.findMaxConsecutiveOnes(nums1) << endl;  // 3
//	cout << s.findMaxConsecutiveOnes(nums2) << endl;  // 2
//	return 0;
//}
