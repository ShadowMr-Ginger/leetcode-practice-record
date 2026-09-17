/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？



示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
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

class Solution70 {
public:
    int climbStairs(int n) {
        int last_step = 1; // 从0阶开始
        int last_last_step = 0;
        int current_step = 0;;
        for (int i = 1;i <= n;i++) {
            current_step = last_step + last_last_step;
            last_last_step = last_step;
            last_step = current_step;
        }
        return current_step;
    }
};

//int main() {
//	Solution70 solution;
//	int n = 5;
//	int result = solution.climbStairs(n);
//	cout << "Number of ways to climb " << n << " stairs: " << result << endl;
//	return 0;
//}