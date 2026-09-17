
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


//  原始代码
class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> verify_list = { 0,0,0,0,0,0,0,0,0 };

        for (int i = 0;i < 9;i++) {
            // 行
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == 46) {
                    continue;
                }
                if (!verify_list[board[i][j] - 49]) {
                    verify_list[board[i][j] - 49] = true;
                }
                else {
                    return false;
                }
            }
            verify_list = { 0,0,0,0,0,0,0,0,0 };

            // 列
            for (int j = 0;j < 9;j++) {
                if (board[j][i] == 46) {
                    continue;
                }
                if (!verify_list[board[j][i] - 49]) {
                    verify_list[board[j][i] - 49] = true;
                }
                else {
                    return false;
                }
            }
            verify_list = { 0,0,0,0,0,0,0,0,0 };
        }

        // 3*3
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                for (int k = 0;k < 3;k++) {
                    for (int h = 0;h < 3;h++) {
                        if (board[i * 3 + k][j * 3 + h] == 46) {
                            continue;
                        }
                        if (!verify_list[board[i * 3 + k][j * 3 + h] - 49]) {
                            verify_list[board[i * 3 + k][j * 3 + h] - 49] = true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                verify_list = { 0,0,0,0,0,0,0,0,0 };
            }
        }


        return true;
    }
};

// AI优化后的代码，使用位运算来减少空间和时间复杂度
class Solution36_PLUS {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用位运算优化：每个 int 的低 9 位记录 1-9 是否出现过
        int rows[9] = { 0 };
        int cols[9] = { 0 };
        int boxes[9] = { 0 };

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                // 将字符 '1'-'9' 映射为 0-8 的位索引
                int bit = 1 << (c - '1');

                // 巧妙计算当前坐标属于哪个 3x3 宫格 (0-8)
                int boxIndex = (i / 3) * 3 + j / 3;

                // 如果该位已经被置为 1，说明重复，直接返回 false
                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[boxIndex] & bit)) {
                    return false;
                }

                // 将该位置为 1，标记已出现
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[boxIndex] |= bit;
            }
        }
        return true;
    }
};


//int main() {
//	Solution36 solution;
//	vector<vector<char>> board = {
//		{'5','3','.','.','7','.','.','.','.'},
//		{'6','.','.','1','9','5','.','.','.'},
//		{'.','9','8','.','.','.','.','6','.'},
//		{'8','.','.','.','6','.','.','.','3'},
//		{'4','.','.','8','.','3','.','.','1'},
//		{'7','.','.','.','2','.','.','.','6'},
//		{'.','6','.','.','.','.','2','8','.'},
//		{'.','.','.','4','1','9','.','.','5'},
//		{'.','.','.','.','8','.','.','7','9'}
//	};
//	bool isValid = solution.isValidSudoku(board);
//	cout << (isValid ? "true" : "false") << endl;
//	return 0;
//}