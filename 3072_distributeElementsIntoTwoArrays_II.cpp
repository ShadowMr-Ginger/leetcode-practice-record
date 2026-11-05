#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution3072 {
    // 树状数组：arr1 中的元素记 +1，arr2 中的元素记 -1
    // 这样“后缀和”就等于 greaterCount(arr1,x) - greaterCount(arr2,x)
    vector<int> tree;
    int n;

    int lowbit(int x) { return x & -x; }

    void add(int i, int delta) {
        for (;i <= n;i += lowbit(i)) tree[i] += delta;
    }

    // 查询 [1, i] 前缀和
    int query(int i) {
        int s = 0;
        for (;i > 0;i -= lowbit(i)) s += tree[i];
        return s;
    }

public:
    vector<int> resultArray(vector<int>& nums) {
        int m = nums.size();
        // 1. 离散化，树状数组按下标统计
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        n = sorted.size();
        tree.assign(n + 1, 0);

        vector<int> arr1, arr2;
        // 2. 前两个元素按题意分别放入 arr1、arr2
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int idx1 = lower_bound(sorted.begin(), sorted.end(), nums[0]) - sorted.begin() + 1;
        int idx2 = lower_bound(sorted.begin(), sorted.end(), nums[1]) - sorted.begin() + 1;
        add(idx1, 1);
        add(idx2, -1);

        // 3. 依次处理剩余元素
        for (int i = 2;i < m;i++) {
            int idx = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            // 当前共 i 个已分配元素，严格大于 nums[i] 的后缀和即两数组 greaterCount 之差
            int diff = i - query(idx);
            if (diff > 0) {
                arr1.push_back(nums[i]);
                add(idx, 1);
            } else {
                arr2.push_back(nums[i]);
                add(idx, -1);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

//int main() {
//	Solution3072 sol;
//	vector<int> nums1 = {2, 1, 3, 3};
//	vector<int> res1 = sol.resultArray(nums1);
//	for (int x : res1) cout << x << " ";
//	cout << endl;
//	vector<int> nums2 = {5, 14, 3, 1};
//	vector<int> res2 = sol.resultArray(nums2);
//	for (int x : res2) cout << x << " ";
//	cout << endl;
//	return 0;
//}
