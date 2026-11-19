#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution3824 {
public:
    int minimumK(vector<int>& nums, int limit) {
        int max_num = *max_element(nums.begin(), nums.end());
        // limit 为 0 时答案会走到 max_num + 1
        int left = 1, right = max_num;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canReduce(nums, limit, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

private:
    // 每个数整除 k，判断总和是否不超过 limit
    bool canReduce(vector<int>& nums, int limit, int k) {
        long long sum = 0;
        for (int x : nums) {
            sum += x / k;
            if (sum > limit) return false;
        }
        return true;
    }
};

//int main() {
//	Solution3824 sol;
//	vector<int> nums1 = {10, 20, 30};
//	cout << sol.minimumK(nums1, 6) << endl;
//	vector<int> nums2 = {1, 2, 3};
//	cout << sol.minimumK(nums2, 100) << endl;
//	return 0;
//}
