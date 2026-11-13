#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution659 {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> tail;
        for (int num : nums) {
            freq[num]++;
        }
        for (int num : nums) {
            if (freq[num] == 0) {
                continue;
            }
            // 优先接到已有连续子序列末尾
            if (tail[num - 1] > 0) {
                tail[num - 1]--;
                tail[num]++;
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                // 否则新开一段长度至少为 3 的子序列
                freq[num + 1]--;
                freq[num + 2]--;
                tail[num + 2]++;
            } else {
                return false;
            }
            freq[num]--;
        }
        return true;
    }
};

//int main() {
//	Solution659 solution;
//	vector<int> nums = {1, 2, 3, 3, 4, 5};
//	cout << solution.isPossible(nums) << endl;
//	vector<int> nums2 = {1, 2, 3, 4, 4, 5};
//	cout << solution.isPossible(nums2) << endl;
//	return 0;
//}
