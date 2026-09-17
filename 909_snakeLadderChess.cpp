/*
给你一个大小为 n x n 的整数矩阵 board ，方格按从 1 到 n2 编号，编号遵循 转行交替方式 ，从左下角开始 （即，从 board[n - 1][0] 开始）的每一行改变方向。

你一开始位于棋盘上的方格  1。每一回合，玩家需要从当前方格 curr 开始出发，按下述要求前进：

选定目标方格 next ，目标方格的编号在范围 [curr + 1, min(curr + 6, n2)] 。
该选择模拟了掷 六面体骰子 的情景，无论棋盘大小如何，玩家最多只能有 6 个目的地。
传送玩家：如果目标方格 next 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 next 。
当玩家到达编号 n2 的方格时，游戏结束。
如果 board[r][c] != -1 ，位于 r 行 c 列的棋盘格中可能存在 “蛇” 或 “梯子”。那个蛇或梯子的目的地将会是 board[r][c]。编号为 1 和 n2 的方格不是任何蛇或梯子的起点。

注意，玩家在每次掷骰的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，玩家也 不能 继续移动。

举个例子，假设棋盘是 [[-1,4],[-1,3]] ，第一次移动，玩家的目标方格是 2 。那么这个玩家将会顺着梯子到达方格 3 ，但 不能 顺着方格 3 上的梯子前往方格 4 。（简单来说，类似飞行棋，玩家掷出骰子点数后移动对应格数，遇到单向的路径（即梯子或蛇）可以直接跳到路径的终点，但如果多个路径首尾相连，也不能连续跳多个路径）
返回达到编号为 n2 的方格所需的最少掷骰次数，如果不可能，则返回 -1。


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

// 原方法 BFS，按层遍历，记录每一层的点，前进六步遍历，将踩过的点标记为0，如果遇到梯子或蛇则传送到目的地，直到到达终点
// 核心效率瓶颈：每次都要将idx转换为二维坐标，导致时间复杂度较高
// 优化方法：将idx转换为二维坐标的过程提前计算好，存储在一个数组中，避免每次都要计算
class Solution909 {
private:
    int n = 0;
public:
    vector<int> idx2location(int idx) {
        vector<int> location = { 0,0 };
        int level = (idx - 1) / n;
        location[0] = n - 1 - level;
        if (level % 2) {
            location[1] = n * (level + 1) - idx;
        }
        else {
            location[1] = idx - 1 - n * level;
        }

        return location;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> targetlist;
        targetlist.push(1);
        int now_rounds = 0;
        bool reached = false;
        while (!targetlist.empty()) {
            int crt_sz = targetlist.size();
            now_rounds++;
            for (int i = 0;i < crt_sz;i++) {
                int pos = targetlist.front();
                // 对targetlist每个点前进六步遍历
                for (int j = 1;j <= 6;j++) {
                    vector<int> nxt_pos = idx2location(pos + j);
                    int x = nxt_pos[0];
                    int y = nxt_pos[1];
                    int tgt = 0;
                    if (board[x][y] == 0) {
                        continue;
                    }
                    else if (board[x][y] == -1) {
                        tgt = pos + j;
                    }
                    else {
                        tgt = board[x][y];
                    }
                    if (tgt == n * n) {
                        reached = true;
                        break;
                    }
                    board[x][y] = 0; // 将当前点标记为0，代表已经踩过这个点了，不要再踩了
                    targetlist.push(tgt);
                }
                targetlist.pop();
                if (reached) {
                    break;
                }
            }
            if (reached) {
                break;
            }
        }
        if (!reached) {
            now_rounds = -1;
        }
        return now_rounds;
    }
};


// 优化方案：将二维坐标转换为一维索引的过程提前计算好，存储在一个数组中，避免每次都要计算
class Solution909_PLUS {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // 1. 预处理：将二维棋盘拉平为一维数组，彻底消除 BFS 中的二维坐标转换
        int target = n * n;
        vector<int> cells(target + 1, -1);
        int idx = 1;
        for (int r = n - 1; r >= 0; --r) {
            // 偶数行（从下往上数）从左到右，奇数行从右到左
            bool is_odd_row = ((n - 1 - r) % 2 == 1);
            for (int c = 0; c < n; ++c) {
                int col = is_odd_row ? (n - 1 - c) : c;
                cells[idx++] = board[r][col];
            }
        }

        queue<int> targetlist;
        targetlist.push(1);
        int now_rounds = 0;
        bool reached = false;
        while (!targetlist.empty()) {
            int crt_sz = targetlist.size();
            now_rounds++;
            for (int i = 0;i < crt_sz;i++) {
                int pos = targetlist.front();
                // 对targetlist每个点前进六步遍历
                for (int j = 1;j <= 6;j++) {
                    int nxt_pos = pos + j;
                    int tgt = 0;
                    if (cells[nxt_pos] == 0) {
                        continue;
                    }
                    else if (cells[nxt_pos] == -1) {
                        tgt = pos + j;
                    }
                    else {
                        tgt = cells[nxt_pos];
                    }
                    if (tgt == target) {
                        reached = true;
                        break;
                    }
                    cells[nxt_pos] = 0; // 将当前点标记为0，代表已经踩过这个点了，不要再踩了
                    targetlist.push(tgt);
                }
                targetlist.pop();
                if (reached) {
                    break;
                }
            }
            if (reached) {
                break;
            }
        }
        if (!reached) {
            now_rounds = -1;
        }
        return now_rounds;
    }
};





//int main() {
//	Solution909 sol;
//	vector<vector<int>> board = { {-1,-1,-1,-1,-1,-1},
//								   {-1,-1,-1,-1,-1,-1},
//								   {-1,-1,-1,-1,-1,-1},
//								   {-1,35,-1,-1,13,-1},
//								   {-1,-1,-1,-1,-1,-1},
//								   {-1,15,-1,-1,-1,-1} };
//	int result = sol.snakesAndLadders(board);
//	cout << "Minimum number of moves to reach the last square: " << result << endl;
//	return 0;
//}