#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution45 {
public:
	// 边界起跳法（贪心）   O(n)
    int jump1(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int max_position_this_jump = nums[0];
        int max_position_next_jump = nums[0];
        int jump_cnt = 1;

        for (int i = 1;i < n;i++) {
            if (i > max_position_this_jump) {
                // 更新边界
                max_position_this_jump = max_position_next_jump;
                jump_cnt++;
            }
            // 每步计算最远边界
            int current_position_next_jump = i + nums[i];
            if (current_position_next_jump > max_position_next_jump) {
                max_position_next_jump = current_position_next_jump;
            }

        }

        return jump_cnt;
    }


	// 模拟起跳法（贪心算法）， O(n*k)，k是平均跳跃次数
    int jump2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        int current_position = 0;
        int current_range = nums[0];
        int jump_cnt = 0;
        while (true) {
            if (current_position + current_range >= n - 1) {
                jump_cnt++;
                break;
            }

            int next_position = 0;
            int next_range = 0;
            int max_distance = current_range;
            for (int i = 1;i <= current_range;i++) {
                int next_distance = i + nums[current_position + i];
                if (next_distance > max_distance) {
                    max_distance = next_distance;
                    next_position = current_position + i;
                    next_range = nums[current_position + i];
                }
            }

            current_position = next_position;
            current_range = next_range;
            jump_cnt++;

        }

        return jump_cnt;
    }


};

//int main() {
//    vector<int> nums = { 2, 3, 1, 1, 4 };
//    Solution45 sol;
//    int jump_cnt = sol.jump1(nums);
//    cout << "Minimum number of jumps to reach the last index: " << jump_cnt << endl;
//    return 0;
//}