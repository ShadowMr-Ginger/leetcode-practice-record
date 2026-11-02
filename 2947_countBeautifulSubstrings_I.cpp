#include <iostream>
#include <string>
using namespace std;

class Solution2947 {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0;i < n;i++) {
            int vowels = 0;
            int consonants = 0;
            for (int j = i;j < n;j++) {
                // 按是否为元音统计数量
                if (is_vowel(s[j])) {
                    vowels++;
                } else {
                    consonants++;
                }
                // 元音、辅音数量相等且乘积能被 k 整除
                if (vowels == consonants && (long long)vowels * consonants % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

//int main() {
//	Solution2947 sol;
//	string s = "baeyh";
//	int k = 2;
//	cout << sol.beautifulSubstrings(s, k) << endl;
//	string s2 = "abba";
//	int k2 = 1;
//	cout << sol.beautifulSubstrings(s2, k2) << endl;
//	return 0;
//}
