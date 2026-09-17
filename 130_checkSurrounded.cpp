/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

连接：一个单元格与水平或垂直方向上相邻的单元格连接。
区域：连接所有 'O' 的单元格来形成一个区域。
围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。



示例 1：

输入：board = [['X','X','X','X'],['X','O','O','X'],['X','X','O','X'],['X','O','X','X']]

输出：[['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']]

解释：


在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。

示例 2：

输入：board = [['X']]

输出：[['X']]
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


// 原方法，扫描，遇到O后先把所有连接的点标记为A，如果被包围则改为X，否则改回O
class Solution130 {
private:
    int directions[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    int n = 0;
    int m = 0;
public:
    void check_surrounded(vector<vector<char>>& board, int x, int y) {
        vector<vector<int>> record_point = { {x, y} };
        int current_pointer = 0;
        bool surrounded = true;
        while (record_point.size() != current_pointer) {
            int c_x = record_point[current_pointer][0];
            int c_y = record_point[current_pointer][1];
            current_pointer++;
            board[c_x][c_y] = 'A';
            for (int i = 0;i < 4;i++) {
                int n_x = c_x + directions[i][0];
                int n_y = c_y + directions[i][1];
                if (n_x >= m || n_x < 0) {
                    surrounded = false;
                }
                else if (n_y >= n || n_y < 0) {
                    surrounded = false;
                }
                else if (board[n_x][n_y] == 'O') {
                    record_point.push_back({ n_x, n_y });
                    board[n_x][n_y] = 'B';
                }
            }
        }
        if (surrounded) {
            for (int i = 0;i < current_pointer;i++) {
                int c_x = record_point[i][0];
                int c_y = record_point[i][1];
                board[c_x][c_y] = 'X';
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 'O') {
                    check_surrounded(board, i, j);
                }
            }
        }
        // 处理A
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }

    }
};


// 新方法，直接从边界的O开始标记所有连接的O为A，其他O改为X，最后将所有A改回O。
class Solution130_PLUS {
private:
    int directions[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    int n = 0;
    int m = 0;
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        queue<vector<int>> q;
        board[x][y] = 'A';
        q.push({ x,y });
        while (!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            for (int k = 0;k < 4;k++) {
                int n_i = i + directions[k][0];
                int n_j = j + directions[k][1];
                if (n_i >= m || n_i < 0 || n_j >= n || n_j < 0) {
                    continue;
                }
                if (board[n_i][n_j] == 'O') {
                    board[n_i][n_j] = 'A';
                    q.push({ n_i,n_j });
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // 先寻找边界O，用dfs改为A
        for (int i = 0;i < m;i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }
        for (int j = 0;j < n;j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j);
            }
        }
        // 处理O 和 A
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};



//int main() {
//	Solution130 solution;
//	vector<vector<char>> board = {
//		{'X','X','X','X'},
//		{'X','O','O','X'},
//		{'X','X','O','X'},
//		{'X','O','X','X'}
//	};
//	solution.solve(board);
//	for (const auto& row : board) {
//		for (char cell : row) {
//			cout << cell << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}