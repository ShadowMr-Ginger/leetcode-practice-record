#include <iostream>
#include <vector>
using namespace std;

class Solution1287 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        // 数组有序，直接统计相邻相同元素个数
        for (int i = 1;i < n;i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > n / 4) {
                return arr[i];
            }
        }
        return arr[0];
    }
};

//int main() {
//	Solution1287 solution;
//	vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
//	cout << solution.findSpecialInteger(arr) << endl;
//	return 0;
//}
