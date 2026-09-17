/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


// 原来写的算法
class Solution73 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }

        bool first_row = false;
        bool first_col = false;

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        first_row = true;
                    }
                    if (j == 0) {
                        first_col = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        if (m > 1) {
            for (int i = 1;i < m;i++) {
                if (matrix[i][0] == 0) {
                    for (int j = 0;j < n;j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (n > 1) {
            for (int j = 1;j < n;j++) {
                if (matrix[0][j] == 0) {
                    for (int i = 0;i < m;i++) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (first_row) {
            for (int j = 0;j < n;j++) {
                matrix[0][j] = 0;
            }
        }

        if (first_col) {
            for (int i = 0;i < m;i++) {
                matrix[i][0] = 0;
            }
        }

    }
};



// AI优化后的代码，使用倒序遍历内部矩阵，避免破坏第一行/列的标记，同时减少不必要的循环，提高性能

class Solution73_PLUS {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;

        bool first_row = false, first_col = false;

        // 1. 遍历整个矩阵，记录0的位置到第一行和第一列
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) first_row = true;
                    if (j == 0) first_col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 2. 倒序遍历内部矩阵（从右下角到左上角），根据标记置零
        // 倒序遍历可以确保在修改当前元素时，不会破坏第一行/列的标记
        for (int i = m - 1; i >= 1; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 3. 处理第一行
        if (first_row) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // 4. 处理第一列
        if (first_col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};


//int main() {
//	Solution73 solution;
//	vector<vector<int>> matrix = {
//		{1, 1, 1},
//		{1, 0, 1},
//		{1, 1, 1}
//	};
//	solution.setZeroes(matrix);
//	for (const auto& row : matrix) {
//		for (const auto& elem : row) {
//			cout << elem << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}