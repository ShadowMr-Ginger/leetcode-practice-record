#include <iostream>
#include <string>
using namespace std;

class Solution3029 {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        // 1. 枚举经过 t 秒共移动 d=t*k 个字符，找最小可行 t
        for (int d = k; d < n; d += k) {
            bool ok = true;
            // 2. 还没被移走的原串后缀必须等于同长度的前缀
            for (int i = 0;i + d < n;i++) {
                if (word[i] != word[i + d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return d / k;
        }
        // 3. 没有完全匹配的前缀后缀，就直接整体替换成原串
        return (n + k - 1) / k;
    }
};

//int main() {
//	Solution3029 sol;
//	cout << sol.minimumTimeToInitialState("abacaba", 3) << endl; // 2
//	return 0;
//}
