#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2616 {
public:
    // 对答案二分：最大的数对差值不超过 mid 时，能否凑出 p 对
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) >= p) {
                // 差值限制为 mid 已够用，尝试更小
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    // 贪心统计：排序后相邻能配就配，配对数最多
    int countPairs(vector<int>& nums, int limit) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= limit) {
                count++;
                i += 2; // 配成一对，跳过两个数
            } else {
                i += 1;
            }
        }
        return count;
    }
};

//int main() {
//	Solution2616 solution;
//	vector<int> nums1 = {10, 1, 2, 7, 1, 3};
//	cout << solution.minimizeMax(nums1, 2) << endl; // 1
//	vector<int> nums2 = {4, 2, 1, 2};
//	cout << solution.minimizeMax(nums2, 1) << endl; // 0
//	return 0;
//}
