#include <iostream>
#include <string>
using namespace std;

class Solution2423 {
public:
    bool equalizeFrequency(string word) {
        int cnt[26] = {0};
        for (char c : word) {
            cnt[c - 'a']++;
        }

        // 依次模拟删掉某个字母的一次出现
        for (int i = 0;i < 26;i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            if (same_frequency(cnt)) {
                return true;
            }
            cnt[i]++;
        }
        return false;
    }

private:
    // 判断非零频次是否全部相同
    bool same_frequency(int cnt[]) {
        int target = -1;
        for (int i = 0;i < 26;i++) {
            if (cnt[i] == 0) continue;
            if (target == -1) {
                target = cnt[i];
            } else if (cnt[i] != target) {
                return false;
            }
        }
        return target != -1;
    }
};

//int main() {
//	Solution2423 solution;
//	cout << solution.equalizeFrequency("abcc") << endl;
//	cout << solution.equalizeFrequency("aazz") << endl;
//	cout << solution.equalizeFrequency("baccc") << endl;
//	return 0;
//}
