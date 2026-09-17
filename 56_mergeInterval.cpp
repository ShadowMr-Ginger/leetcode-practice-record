/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。



示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
示例 3：

输入：intervals = [[4,7],[1,4]]
输出：[[1,7]]
解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;


// 原做法，用排序+遍历的方式，时间复杂度O(nlogn)，空间复杂度O(n)
class Solution56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return {};
        }

        // 排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});

        // 开始合并区间
        int min_left = intervals[0][0];
        int max_right = intervals[0][1];
        vector<vector<int>> ans;

        for (int i = 1;i < n;i++) {
            if (max_right >= intervals[i][0]) {
                max_right = max(max_right, intervals[i][1]);
            }
            else {
                ans.push_back({ min_left, max_right });
                min_left = intervals[i][0];
                max_right = intervals[i][1];
            }
        }
        ans.push_back({ min_left, max_right });

        return ans;

    }
};


// AI优化版本，使用排序+遍历的方式，时间复杂度O(nlogn)，空间复杂度O(n)

class Solution56_PLUS {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. 按左端点排序（记得加分号）
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });

        vector<vector<int>> ans;
        // 2. 先将第一个区间加入结果集
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // 3. 获取结果集中最后一个区间的右边界（引用传递，直接修改）
            int& last_right = ans.back()[1];

            if (last_right >= intervals[i][0]) {
                // 4. 有重叠：直接更新最后一个区间的右边界（取最大值）
                last_right = max(last_right, intervals[i][1]);
            }
            else {
                // 5. 无重叠：直接将当前区间加入结果集
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};


//int main() {
//	Solution56 solution;
//	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
//	vector<vector<int>> ans = solution.merge(intervals);
//	for (auto& interval : ans) {
//		cout << "[" << interval[0] << "," << interval[1] << "] ";
//	}
//	cout << endl;
//	return 0;
//}