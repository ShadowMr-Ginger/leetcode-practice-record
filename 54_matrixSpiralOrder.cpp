
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/


class Solution54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        if (m == 1) {
            return matrix[0];
        }
        int n = matrix[0].size();
        if (n == 0) {
            return {};
        }

        // 初始位置
        vector<int> pos = { 0,0 };

        // 方向向量（按逆时针顺序）
        vector<vector<int>> direct_vec = { {0,1},{1,0},{0,-1},{-1,0} };

        // 右边界为n
        // 下边界为m
        // 左边界初始化为0
        // 上边界初始化为0
        vector<int> border = { n,m,0,0 };

        int current_direct = 0; // 初方向为右

        vector<int> ans(m * n, 0); // 初始化答案

        ans[0] = matrix[0][0];
        int pt = 0;

        while (true) {
            // 准备移动，判断移动方向上是否到头
            bool reach_end = false;
            if (current_direct == 0) {
                if (pos[1] + 1 == border[0]) {
                    reach_end = true;
                    border[3]++; // 更新上边界
                }
            }
            else if (current_direct == 1) {
                if (pos[0] + 1 == border[1]) {
                    reach_end = true;
                    border[0]--;// 更新右边界
                }
            }
            else if (current_direct == 2) {
                if (pos[1] - 1 < border[2]) {
                    reach_end = true;
                    border[1]--;// 更新下边界
                }
            }
            else {
                if (pos[0] - 1 < border[3]) {
                    reach_end = true;
                    border[2]++;// 更新左边界
                }
            }


            // 若达边，转向
            if (reach_end) {
                // 先检查是否左右/上下边界重合，若重合，代表已结束。
                if (border[0] == border[2] || border[1] == border[3]) {
                    break;
                }
                current_direct = (current_direct + 1) % 4;
            }

            pos[0] += direct_vec[current_direct][0];
            pos[1] += direct_vec[current_direct][1];
            pt++;
            ans[pt] = matrix[pos[0]][pos[1]];

        }

        return ans;
    }
};







//AI优化后的代码，使用数组代替vector，减少内存分配，提高性能

class Solution54_PLUS {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int m = matrix.size(), n = matrix[0].size();
        // 使用栈上数组代替 vector，性能更好
        int directions[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

        // 初始化四个边界
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int dirIndex = 0; // 当前方向索引
        int row = 0, col = 0; // 当前位置

        while (top <= bottom && left <= right) {
            // 1. 按照当前方向遍历一条边
            if (dirIndex == 0) { // 向右
                for (int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
                top++; // 上边界下移
            }
            else if (dirIndex == 1) { // 向下
                for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
                right--; // 右边界左移
            }
            else if (dirIndex == 2) { // 向左
                for (int i = right; i >= left; --i) res.push_back(matrix[bottom][i]);
                bottom--; // 下边界上移
            }
            else { // 向上
                for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
                left++; // 左边界右移
            }
            // 2. 顺时针切换方向
            dirIndex = (dirIndex + 1) % 4;
        }
        return res;
    }
};


//int main() {
//	Solution54 solution;
//	vector<vector<int>> matrix = {
//		{1, 2, 3},
//		{4, 5, 6},
//		{7, 8, 9}
//	};
//	vector<int> result = solution.spiralOrder(matrix);
//	for (int num : result) {
//		cout << num << " ";
//	}
//	cout << endl;
//	return 0;
//}