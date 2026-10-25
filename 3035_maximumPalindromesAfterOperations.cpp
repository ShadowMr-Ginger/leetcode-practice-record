#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution3035 {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int freq[26] = {0};
        for (const string& w : words) {
            for (char ch : w) {
                freq[ch - 'a']++;
            }
        }

        // 能自由交换时，回文只消耗“相同字符对”
        int pairs = 0;
        for (int i = 0;i < 26;i++) {
            pairs += freq[i] / 2;
        }

        // 每个单词变成回文需要 len/2 对，按代价从小到大贪
        vector<int> cost;
        for (const string& w : words) {
            cost.push_back((int)w.size() / 2);
        }
        sort(cost.begin(), cost.end());

        int ans = 0;
        for (int c : cost) {
            if (pairs < c) {
                break;
            }
            pairs -= c;
            ans++;
        }
        return ans;
    }
};

//int main() {
//	Solution3035 sol;
//	vector<string> words = {"abbb", "ba", "aa"};
//	cout << sol.maxPalindromesAfterOperations(words) << endl;
//	return 0;
//}
