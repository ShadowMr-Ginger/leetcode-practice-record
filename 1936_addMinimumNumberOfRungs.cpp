#include <iostream>
#include <vector>

using namespace std;

class Solution1936 {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int count = 0;
        int prev = 0; // 起点在地面，高度为 0
        for (int i = 0;i < rungs.size();i++) {
            int gap = rungs[i] - prev;
            // 间距超过 dist 时，中间需补 (gap - 1) / dist 个横杆
            if (gap > dist) {
                count += (gap - 1) / dist;
            }
            prev = rungs[i];
        }
        return count;
    }
};

//int main() {
//	Solution1936 s;
//	vector<int> rungs = {1, 3, 5, 10};
//	cout << s.addRungs(rungs, 2) << endl; // 输出 2
//	return 0;
//}
