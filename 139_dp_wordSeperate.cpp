/*

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。



示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <stack>
#include <array>
#include <numeric>
#include <queue>
using namespace std;

// 原方法：动态规划，f(k)表示前k个字符是否可以由字典中的单词拼接而成，
// f(k) = true if there exists j < k such that f(j) is true and s[j:k] is in wordDict。
// 即如果前j个字符可以由字典中的单词拼接而成，并且s[j:k]在字典中，则前k个字符也可以由字典中的单词拼接而成。
class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }
        int len = s.length();
        // 逐字符检查
        vector<bool> canCompose(len, false); // dp数组，canCompose[x]表示直到第x个字符为止都是可构成的
        for (int i = 0;i < len;i++) {
            if (wordDictSet.count(s.substr(0, i + 1))) {
                canCompose[i] = true;
                continue;
            }
            for (int j = 0;j < i;j++) {
                if (canCompose[j]) {
                    if (wordDictSet.count(s.substr(j + 1, i - j))) {
                        canCompose[i] = true;
                        break;
                    }
                }
            }
        }

        return(canCompose[len - 1]);
    }
};


// AI优化方法，提升性能，通过限制内层循环的范围，减少不必要的检查。
// 通过计算字典中最长单词的长度，内层循环只需要检查从当前位置往回看最长单词长度的范围，
// 从而减少了不必要的子串检查，提高了效率。
class Solution139_PLUS {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 1. 构建哈希集合
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // 2. 找出字典中最长单词的长度，用于限制内层循环
        int maxLen = 0;
        for (const auto& word : wordDict) {
            maxLen = max(maxLen, (int)word.length());
        }

        int n = s.length();
        // 3. 引入虚拟节点，dp[i] 表示 s 的前 i 个字符能否被拆分
        vector<bool> dp(n + 1, false);
        dp[0] = true; // 空串总是可以被拆分

        for (int i = 1; i <= n; ++i) {
            // 4. 核心优化：只往回看 maxLen 个字符，且不能越界
            // j 代表分割点，s[j...i) 是我们要检查的子串
            // 子串长度 = i - j，必须 <= maxLen，所以 j >= i - maxLen
            for (int j = max(0, i - maxLen); j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // 只要找到一种拆分方式，立刻跳出
                }
            }
        }
        return dp[n];
    }
};


//int main() {
//	Solution139 solution;
//	string s = "leetcode";
//	vector<string> wordDict = { "leet", "code" };
//	bool result = solution.wordBreak(s, wordDict);
//	cout << "Can the string \"" << s << "\" be segmented into words from the dictionary? " << (result ? "Yes" : "No") << endl;
//	return 0;
//}