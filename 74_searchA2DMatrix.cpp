#include <iostream>
#include <vector>

using namespace std;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        // 把二维矩阵看成一维有序数组做二分
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

//int main() {
//	Solution74 solution;
//	vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//	cout << solution.searchMatrix(matrix, 3) << endl;
//	cout << solution.searchMatrix(matrix, 13) << endl;
//	return 0;
//}
