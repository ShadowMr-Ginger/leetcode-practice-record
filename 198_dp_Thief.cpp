/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。



示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。


提示：

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <array>
#include <numeric>
#include <queue>
using namespace std;



// 动态规划，f(k)表示偷窃前k间房屋的最高金额，f(k) = max(f(k-1), f(k-2)+nums[k])，即第k间房屋若偷，则最高金额为f(k-2)+nums[k]，若不偷，最高金额就是f(k-1)。对比一下偷与不偷，得到max_rob

class Solution198 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f_k_2 = nums[0]; //初始化 f(k-2)最大值 
        if (n == 1) {
            return nums[0];
        }
        int f_k_1 = max(nums[0], nums[1]);//初始化 f(k-1)最大值
        int max_rob = f_k_1;
        for (int k = 2;k < n;k++) {
            // 第k间若偷，则最高金额为f(k-2)+nums[k]
            int current_stole = f_k_2 + nums[k];
            // 若不偷，最高金额就是f(k-1)。对比一下偷与不偷，得到max_rob
            max_rob = max(current_stole, f_k_1);
            // 更新到下一个
            f_k_2 = f_k_1;
            f_k_1 = max_rob;
        }
        return max_rob;
    }
};

//
//int main() {
//	Solution198 solution;
//	vector<int> nums = { 2,7,9,3,1 };
//	int result = solution.rob(nums);
//	cout << "Maximum amount that can be robbed: " << result << endl;
//	return 0;
//}
//
