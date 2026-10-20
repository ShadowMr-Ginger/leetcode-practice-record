#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        return helper(nums1, nums2);
    }

private:
    double helper(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left_size = (m + n + 1) / 2;
        int low = 0;
        int high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = left_size - i;

            int nums1_left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right = (i == m) ? INT_MAX : nums1[i];
            int nums2_left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right = (j == n) ? INT_MAX : nums2[j];

            // 合法切分：左半最大值不超过右半最小值
            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                int max_left = max(nums1_left, nums2_left);
                if ((m + n) % 2 == 1) {
                    return max_left;
                }
                int min_right = min(nums1_right, nums2_right);
                return ((double)max_left + min_right) / 2.0;
            }

            if (nums1_left > nums2_right) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};

//int main() {
//	Solution4 solution;
//	vector<int> nums1 = {1, 3};
//	vector<int> nums2 = {2};
//	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
//
//	nums1 = {1, 2};
//	nums2 = {3, 4};
//	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
//
//	return 0;
//}
