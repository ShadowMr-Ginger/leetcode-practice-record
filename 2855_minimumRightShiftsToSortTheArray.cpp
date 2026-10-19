#include <iostream>
#include <vector>
using namespace std;

class Solution2855 {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int drop_count = 0;
        int drop_index = -1;

        // 1. 找数组中严格下降的位置
        for (int i = 1;i < n;i++) {
            if (nums[i] < nums[i - 1]) {
                drop_count++;
                drop_index = i;
            }
        }

        // 2. 没有下降说明已经有序；多于一处下降无法通过右移变有序
        if (drop_count == 0) {
            return 0;
        }
        if (drop_count > 1) {
            return -1;
        }

        // 3. 旋转数组还需满足末尾不大于开头，右移次数为 n - drop_index
        if (nums[n - 1] > nums[0]) {
            return -1;
        }
        return n - drop_index;
    }
};

//int main() {
//	Solution2855 solution;
//	vector<int> nums1 = {3,4,5,1,2};
//	vector<int> nums2 = {1,3,5};
//	cout << solution.minimumRightShifts(nums1) << endl;
//	cout << solution.minimumRightShifts(nums2) << endl;
//	return 0;
//}
