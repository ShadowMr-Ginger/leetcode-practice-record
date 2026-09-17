/*


根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是 同时 发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。

给定当前 board 的状态，更新 board 到下一个状态。

注意 你不需要返回任何东西。

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


// 状态法
class Solution289 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        if (n == 0) {
            return;
        }

        // 记录一个8方向表
        int direct[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

        // 开始遍历

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                int neighbour_lives = 0;
                for (int k = 0;k < 8;k++) {
                    int pos[2] = { i + direct[k][0],j + direct[k][1] };
                    if (pos[0] > -1 && pos[0]<m && pos[1]>-1 && pos[1] < n) {
                        neighbour_lives += board[pos[0]][pos[1]] % 2;
                    }
                }
                if (board[i][j]) {
                    if (neighbour_lives < 2 || neighbour_lives>3) {
                        // 待死，将1变为3表示由1变0的待死状态
                        board[i][j] = 3;
                    }
                }
                else {
                    if (neighbour_lives == 3) {
                        // 待活，将0变为2表示由0变1的待活状态
                        board[i][j] = 2;
                    }
                }
            }
        }

        // 更新全表等待状态
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }

    }
};


//int main() {
//	Solution289 sol;
//	vector<vector<int>> board = {
//		{0, 1, 0},
//		{0, 0, 1},
//		{1, 1, 1},
//		{0, 0, 0}
//	};
//	sol.gameOfLife(board);
//	cout << "Next state of the board:" << endl;
//	for (const auto& row : board) {
//		for (int cell : row) {
//			cout << cell << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}