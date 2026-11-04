#include <iostream>
#include <vector>

using namespace std;

class Solution162 {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }

        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 上坡就往右找峰，否则峰在左边或就是 mid
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

//int main() {
//	Solution162 solution;
//	vector<int> nums = {1, 2, 3, 1};
//	cout << solution.findPeakElement(nums) << endl;
//	vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
//	cout << solution.findPeakElement(nums2) << endl;
//	return 0;
//}
