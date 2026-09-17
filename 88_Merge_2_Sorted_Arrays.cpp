#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt_total = m + n - 1;
        int pt1 = m - 1;
        int pt2 = n - 1;
        while (pt_total != -1) {
            if (pt1 == -1) {
                nums1[pt_total] = nums2[pt2];
                pt2--;
                pt_total--;
            }
            else if (pt2 == -1) {
                nums1[pt_total] = nums1[pt1];
                pt1--;
                pt_total--;
            }
            else {
                if (nums1[pt1] >= nums2[pt2]) {
                    nums1[pt_total] = nums1[pt1];
                    pt1--;
                    pt_total--;
                }
                else {
                    nums1[pt_total] = nums2[pt2];
                    pt2--;
                    pt_total--;
                }
            }
        }
    }
};

//int main() {
//	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
//	int m = 3;
//	vector<int> nums2 = { 2, 5, 6 };
//	int n = 3;
//	Solution88 sol;
//	sol.merge(nums1, m, nums2, n);
//	for (int x : nums1) cout << x << ' ';
//	cout << endl;
//	return 0;
//}