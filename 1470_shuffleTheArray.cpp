#include <iostream>
#include <vector>

using namespace std;

class Solution1470 {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        result.reserve(2 * n);
        // 前半段为 x，后半段为 y，依次交错放入
        for (int i = 0;i < n;i++) {
            result.push_back(nums[i]);
            result.push_back(nums[i + n]);
        }
        return result;
    }
};

//int main() {
//	Solution1470 s;
//	vector<int> nums = {2, 5, 1, 3, 4, 7};
//	vector<int> ans = s.shuffle(nums, 3);
//	for (int x : ans) {
//		cout << x << " ";
//	}
//	cout << endl;
//	return 0;
//}
