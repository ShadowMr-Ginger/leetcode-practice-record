#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution2271 {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        int max_cover = 0;
        int cover = 0; // 窗口 [left, right] 完整覆盖的白砖数
        int left = 0;
        for (int right = 0;right < n;right++) {
            cover += tiles[right][1] - tiles[right][0] + 1;
            // 地毯左端对齐 tiles[left][0]，长度放不下时收缩左边界
            while (tiles[right][1] - tiles[left][0] + 1 > carpetLen) {
                // 超出部分就是 tiles[right] 右端没被盖住的白砖
                int uncovered = tiles[right][1] - tiles[left][0] + 1 - carpetLen;
                max_cover = max(max_cover, cover - uncovered);
                cover -= tiles[left][1] - tiles[left][0] + 1;
                left++;
            }
            max_cover = max(max_cover, cover);
        }
        return max_cover;
    }
};

//int main() {
//	Solution2271 s;
//	vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}};
//	cout << s.maximumWhiteTiles(tiles, 10) << endl; // 9
//	vector<vector<int>> tiles2 = {{10,11},{1,1}};
//	cout << s.maximumWhiteTiles(tiles2, 2) << endl; // 2
//	return 0;
//}
