#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution1913 {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        int n = nums.size();
        // 1. 遍历维护最大两个数和最小两个数
        for (int i = 0;i < n;i++) {
            int x = nums[i];
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }
        // 2. 最大乘积减去最小乘积
        return max1 * max2 - min1 * min2;
    }
};

//int main() {
//	vector<int> nums = {5,6,2,7,4};
//	cout << Solution1913().maxProductDifference(nums) << endl;
//	return 0;
//}
