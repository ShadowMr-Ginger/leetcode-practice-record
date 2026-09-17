#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution80 {
public:
    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        // 长度小于等于2的数组，必然满足条件，直接返回
        if (n <= 2) return n;

        // 前两个元素肯定可以直接保留，所以慢指针 pt 从 2 开始
        int pt = 2;

        // 快指针从第 3 个元素（索引2）开始遍历
        for (int fast = 2; fast < n; ++fast) {
            // 核心：当前元素 不等于 写入位置的前第2个元素
            // 说明没有连续出现3次，可以安全保留
            if (nums[fast] != nums[pt - 2]) {
                nums[pt++] = nums[fast];
            }
        }
        return pt;
    }
};

//int main() {
//	vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	Solution80 sol;
//	int new_length = sol.removeDuplicates2(nums);
//	cout << "New length: " << new_length << endl;
//	cout << "Modified array: ";
//	for (int i = 0; i < new_length; i++) {
//		cout << nums[i] << ' ';
//	}
//	cout << endl;
//	return 0;
//}