#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution28 {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size(); // right 指向尾后

        while (left < right) {
            if (nums[left] == val) {
                // 发现目标值，把末尾的元素拿过来覆盖，right 左移
                right--;
                nums[left] = nums[right];
            }
            else {
                // 不是目标值，left 正常右移
                left++;
            }
        }
        return left; // 此时 left 正好是不等于 val 的元素个数
    }
};

//int main() {
//	vector<int> nums = { 3, 2, 2, 3 };
//	int val = 3;
//	Solution28 sol;
//	int new_length = sol.removeElement(nums, val);
//	cout << "New length: " << new_length << endl;
//	cout << "Modified array: ";
//	for (int i = 0; i < new_length; i++) {
//		cout << nums[i] << ' ';
//	}
//	cout << endl;
//	return 0;
//}