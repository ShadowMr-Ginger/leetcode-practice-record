#include <iostream>
#include <vector>

using namespace std;

// 模拟题目提供的 MountainArray 接口，便于本地测试
class MountainArray {
public:
    MountainArray(vector<int>& arr) : arr(arr) {}
    int get(int index) { return arr[index]; }
    int length() { return (int)arr.size(); }
private:
    vector<int> arr;
};

class Solution1095 {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // 1. 二分查找山峰下标（最大值位置）
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peak = left;
        // 2. 先在上升段 [0, peak] 找 target，下标更靠前
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1) {
            return idx;
        }
        // 3. 上升段没找到，再到下降段 [peak+1, n-1] 找
        return binarySearch(mountainArr, target, peak + 1, n - 1, false);
    }

private:
    // 在单调段内二分找 target，返回最左匹配下标，找不到返回 -1
    int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool ascending) {
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                res = mid; // 记录答案，继续往左找更靠前的
                right = mid - 1;
            } else if ((val < target) == ascending) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

//int main() {
//	vector<int> arr = {1,2,3,4,5,3,1};
//	MountainArray mountainArr(arr);
//	Solution1095 solution;
//	cout << solution.findInMountainArray(2, mountainArr) << endl;
//	cout << solution.findInMountainArray(3, mountainArr) << endl;
//	vector<int> arr2 = {0,1,2,4,2,1};
//	MountainArray mountainArr2(arr2);
//	cout << solution.findInMountainArray(3, mountainArr2) << endl;
//	return 0;
//}
