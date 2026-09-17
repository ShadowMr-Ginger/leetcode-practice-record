/*

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution452{
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) {
            return n;
        }

        // 对 points 的x_start进行排序
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });


        int min_right_border = points[0][1];
        int need_arrows = 0;
        for (int i = 1;i < n;i++) {
            // 若当前气球的左边界大于min_right，则必须射一箭，更新右边界为当前气球右边界
            if (points[i][0] > min_right_border) {
                need_arrows++;
                min_right_border = points[i][1];
                continue;
            }

            //向右遍历，不断更新min_right 和max_left;
            if (points[i][1] < min_right_border) {
                min_right_border = points[i][1];
            }
        }
        // 最后射一箭
        need_arrows++;
        return need_arrows;
    }
};


// AI优化版本，使用 long long 防止溢出，并且逻辑更清晰

class Solution452_PLUS {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;

        // 按左边界排序
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });

        // 使用 long long 防止 INT_MAX 溢出
        long long min_right_border = points[0][1];
        int need_arrows = 1; // 至少需要一支箭，初始化为1更直观

        for (int i = 1; i < n; i++) {
            // 当前气球的左边界 > 最小右边界，说明射不中，必须多用一支箭
            if ((long long)points[i][0] > min_right_border) {
                need_arrows++;
                min_right_border = points[i][1];
            }
            else {
                // 有重叠，更新重叠区间的最小右边界
                // 用 else 避免不必要的判断，逻辑更严密
                min_right_border = min(min_right_border, (long long)points[i][1]);
            }
        }

        return need_arrows;
    }
};



//
//int main() {
//	Solution452 solution;
//	vector<vector<int>> points = { {10,16},{2,8},{1,6},{7,12} };
//	int result = solution.findMinArrowShots(points);
//	cout << "Minimum number of arrows needed: " << result << endl; // Output: 2
//	return 0;
//}
