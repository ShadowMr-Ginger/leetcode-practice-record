#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution55 {
public:

	// 边界起跳法（贪心算法），O(n)
    bool canJump1(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }

        int max_range = 0;

        for (int i = 0;i < n;i++) {
            int current_range = nums[i] + i;
            if (current_range > max_range) {
                max_range = current_range;
            }
            if (i >= max_range) {
                break;
            }
            if (current_range >= n - 1) {
                return true;
            }

        }
        return false;
    }


	// 模拟起跳法（贪心算法），O(n*k)，k是平均跳跃次数
    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        int current_position = 0;
        int current_range = nums[0];
        bool can_reach = false;

        while (true) {
            if (current_position + current_range >= n - 1) {
                can_reach = true;
                break;
            }
            // 用于判断当前下标一次跳跃后是否可以跳到更远的下标
            bool farther_jump = false;
            int next_position = 0;
            int next_range = 0;
            int max_distance = current_range;
            for (int i = 1;i < current_range;i++) {
                int next_distance = i + nums[current_position + i];
                if (next_distance > max_distance) {
                    max_distance = next_distance;
                    next_position = current_position + i;
                    next_range = nums[current_position + i];
                    farther_jump = true;
                }
            }
            if (farther_jump == false) {
                break;
            }
            else {
                current_position = next_position;
                current_range = next_range;
            }

        }

        return can_reach;
    }
};

//int main() {
//	vector<int> nums = { 2, 3, 1, 1, 4 };
//	Solution55 sol;
//	bool can_reach = sol.canJump1(nums);
//	cout << "Can reach the last index: " << (can_reach ? "true" : "false") << endl;
//	return 0;
//}