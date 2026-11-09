#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution2125 {
public:
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int prev = 0; // 上一个非空行的设备数
        for (string& row : bank) {
            // 统计当前行设备数
            int cur = 0;
            for (char c : row) {
                if (c == '1') {
                    cur++;
                }
            }
            // 当前行为空则跳过
            if (cur == 0) {
                continue;
            }
            // 与上一个非空行两两配对
            total += prev * cur;
            prev = cur;
        }
        return total;
    }
};

//int main() {
//	Solution2125 solution;
//	vector<string> bank = {"011001","000000","010100","001000"};
//	cout << solution.numberOfBeams(bank) << endl;
//	return 0;
//}
