#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution757 {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 1. 按右端点升序，右端点相同按左端点降序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int ans = 0;
        int a = -1, b = -1; // 当前已选最大的两个点，a < b
        for (auto& interval : intervals) {
            int left = interval[0];
            int right = interval[1];

            if (a >= left) { // 最大的两个点都在区间内
                continue;
            }

            if (b >= left) { // 只有一个点在区间内，补 right
                ans++;
                a = b;
                b = right;
            } else { // 一个点都没有，补 right-1 和 right
                ans += 2;
                a = right - 1;
                b = right;
            }
        }
        return ans;
    }
};

//int main() {
//	Solution757 solution;
//	vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
//	cout << solution.intersectionSizeTwo(intervals) << endl;
//	return 0;
//}
