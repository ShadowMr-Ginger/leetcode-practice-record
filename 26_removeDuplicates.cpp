#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int pt_final = 1;
        int last_n = nums[0];
        for (auto it = nums.begin() + 1;it != nums.end();it++) {
            if (*it == last_n) {
                continue;
            }
            nums[pt_final] = *it;
            pt_final++;
            last_n = *it;
        }
        return pt_final;
    }
};

//int main() {
//	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
//	Solution26 sol;
//	int new_length = sol.removeDuplicates(nums);
//	cout << "New length: " << new_length << endl;
//	cout << "Modified array: ";
//	for (int i = 0; i < new_length; i++) {
//		cout << nums[i] << ' ';
//	}
//	cout << endl;
//	return 0;
//}