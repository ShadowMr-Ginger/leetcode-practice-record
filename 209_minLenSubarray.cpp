#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 原来的代码
class Solution209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return n;
        }
        int l_pt = 0; // 窗口左指针
        int r_pt = 0; // 窗口右指针
        int current_sum = nums[0]; // 当前和
        int len = 1; // 当前子串长度
        bool found = false; // 是否已经找到符合条件的子串
        int min_len = 0; // 符合条件的最小子串长度

        while (true) {
            if (current_sum >= target) {
                if (!found) {
                    found = true;
                    min_len = len;
                }
                else if (len < min_len) {
                    min_len = len;
                }
            }

            if (current_sum <= target) {
                r_pt++;
                if (r_pt >= n) {
                    break;
                }
                else {
                    current_sum += nums[r_pt];
                }
                len++;
            }
            else {
                current_sum -= nums[l_pt];
                l_pt++;
                len--;
            }
        }
        return min_len;
    }
};

// AI优化后的代码
class Solution209_PLUS {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int left = 0;
        int current_sum = 0;
        int min_len = n + 1; // 初始化为一个不可能的极大值

        // 右指针不断向右扩展窗口
        for (int right = 0; right < n; right++) {
            current_sum += nums[right];

            // 当窗口内的和满足条件时，尝试收缩左指针以寻找更短的子数组
            while (current_sum >= target) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        // 如果 min_len 没被更新过，说明没找到符合条件的子数组
        return min_len == n + 1 ? 0 : min_len;
    }
};

//int main() {
//	Solution209 sol;
//	vector<int> nums = { 5 }; // Example input
//	int target = 7; // Example target
//	int result = sol.minSubArrayLen(target, nums);
//	cout << "The length of the smallest subarray with sum >= " << target << " is: " << result << endl;
//	return 0;
//}