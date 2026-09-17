#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution189 {
public:
	// 解法1 - 直接移动法
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n != 0 && k != 0) {
            int move_cnt = 0;
            int slot = -1;
            while (move_cnt < n) {
                slot++;
                int num = nums[slot];
                int insert_idx = slot;
                while (true) {
                    insert_idx = (insert_idx + k) % n;
                    int t = nums[insert_idx];
                    nums[insert_idx] = num;
                    num = t;
                    move_cnt++;
                    if (insert_idx == slot) {
                        break;
                    }
                }
            }
        }
    }
	// 解法2 - 三次翻转法
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // 这一步非常关键！
        if (k == 0) return;

        // C++ STL 提供的翻转函数，时间复杂度 O(n)
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


//int main() {
//    vector<int> nums = {1,2,3,4,5,6,7};
//    int k = 3;
//    Solution189 sol;          // 注意类名与变量名不要冲突
//    sol.rotate2(nums, k);
//
//    for (int x : nums) cout << x << ' ';
//    cout << endl;
//    return 0;
//}

