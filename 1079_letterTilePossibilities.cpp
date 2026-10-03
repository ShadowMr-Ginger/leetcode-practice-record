#include <iostream>
#include <string>
using namespace std;

class Solution1079 {
public:
    int numTilePossibilities(string tiles) {
        int count[26] = {0};
        for (char ch : tiles) {
            count[ch - 'A']++;
        }
        return backtrack(count);
    }

private:
    int backtrack(int count[]) {
        int ans = 0;
        for (int i = 0;i < 26;i++) {
            if (count[i] == 0) {
                continue;
            }
            // 1. 选中当前字母，长度加一就是一个新序列
            count[i]--;
            ans++;
            // 2. 继续向后拼接更长序列
            ans += backtrack(count);
            // 3. 回溯恢复，供其他分支使用
            count[i]++;
        }
        return ans;
    }
};

//int main() {
//	Solution1079 solution;
//	string tiles = "AAB";
//	cout << solution.numTilePossibilities(tiles) << endl;
//	return 0;
//}
