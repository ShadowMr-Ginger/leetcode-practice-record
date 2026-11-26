#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2062 {
public:
	int countVowelSubstrings(string word) {
		int n = word.size();
		int result = 0;
		int i = 0;
		while (i < n) {
			if (!is_vowel(word[i])) {
				i++;
				continue;
			}
			// 1. 找出一段只含元音的连续区间 [i, j)
			int j = i;
			while (j < n && is_vowel(word[j])) {
				j++;
			}
			// 2. 在区间内统计包含全部 5 个元音的子串
			unordered_map<char, int> last;
			for (int k = i;k < j;k++) {
				last[word[k]] = k;
				if (last.size() == 5) {
					// 以 k 结尾且含全部元音的子串数 = 各元音最早出现位置距区间左端的距离
					int min_pos = k;
					for (auto& p : last) {
						min_pos = min(min_pos, p.second);
					}
					result += min_pos - i + 1;
				}
			}
			i = j;
		}
		return result;
	}

private:
	// 判断是否为元音字母
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
};

//int main() {
//	Solution2062 solution;
//	cout << solution.countVowelSubstrings("aeiouu") << endl;         // 2
//	cout << solution.countVowelSubstrings("unicornarihan") << endl;  // 0
//	cout << solution.countVowelSubstrings("cuaieokou") << endl;      // 1
//	return 0;
//}
