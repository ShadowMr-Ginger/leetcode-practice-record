#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution169 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            }
            else if (num == candidate) {
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};

//int main() {
//	vector<int> nums = { 3, 2, 3 };
//	Solution169 sol;
//	int majority = sol.majorityElement(nums);
//	cout << "Majority element: " << majority << endl;
//	return 0;
//}