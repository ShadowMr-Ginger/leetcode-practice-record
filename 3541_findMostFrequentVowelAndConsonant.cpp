#include <iostream>
#include <string>

using namespace std;

class Solution3541 {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        // 1. 统计每个字母出现次数
        for (int i = 0;i < s.size();i++) {
            cnt[s[i] - 'a']++;
        }

        int max_vowel = 0;
        int max_consonant = 0;
        // 2. 分别找出元音和辅音的最大频次
        for (int i = 0;i < 26;i++) {
            char c = 'a' + i;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                max_vowel = max(max_vowel, cnt[i]);
            } else {
                max_consonant = max(max_consonant, cnt[i]);
            }
        }

        return max_vowel + max_consonant;
    }
};

//int main() {
//	Solution3541 sol;
//	cout << sol.maxFreqSum("successes") << endl;
//	cout << sol.maxFreqSum("aeiaeia") << endl;
//	return 0;
//}
