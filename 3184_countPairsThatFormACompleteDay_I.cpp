#include <iostream>
#include <vector>
using namespace std;

class Solution3184 {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int freq[24] = {0}; // 各余数出现的次数
        int result = 0;
        // 1. 遍历每个小时，先累加能与它凑成 24 倍数的历史个数，再更新频次
        for (int i = 0;i < n;i++) {
            int remainder = hours[i] % 24;
            int complement = (24 - remainder) % 24;
            result += freq[complement];
            freq[remainder]++;
        }
        return result;
    }
};

//int main() {
//	Solution3184 solution;
//	vector<int> hours = {12, 12, 30, 24, 24};
//	cout << solution.countCompleteDayPairs(hours) << endl;
//	return 0;
//}
