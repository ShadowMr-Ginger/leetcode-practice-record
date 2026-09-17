/*
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


/*

暴力法是我原本写的方法。

但是极端用例超时了。
s =
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa。。。
words =
["a","a","a","a","a","a","a"...

这个极端用例超时了
*/
class Solution30 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map <string, int> wordCount;
		
		// 检查输入是否为空
		if (s.empty() || words.empty()) {
			return {};
		}

		// 统计每个单词的出现次数
		for (const string& word : words) {
			wordCount[word]++;
		}

		// 1. 获取单词长度
		int wordLength = words[0].length();

		// 2. 获取单词数量
		int wordCountTotal = words.size();

		// 3. 获取总长度
		int totalLength = wordCountTotal * wordLength;
		
		if (totalLength > s.length()) {
			return {};
		}

		// 4. 获取字符串长度
		int sLength = s.length();

		// 5. 初始化当前计数器
		unordered_map <string, int> currentCount;

		// 6. 初始化结果向量
		vector<int> result;

		// 7. 遍历字符串
		for (int i = 0; i < s.length() - totalLength + 1; i++) {
			string word1 = s.substr(i, wordLength);
			if (wordCount.count(word1) == 0) {
				continue; // 如果当前单词不在 words 中，跳过
			}
			currentCount = wordCount; // 重置当前计数器
			for (int j = 0; j < wordCountTotal; j++) {
				string word2 = s.substr(i + j * wordLength, wordLength);
				if (currentCount.count(word2) == 0 || currentCount[word2] == 0) {
					break; // 如果当前单词不在 words 中，或者已经用完，跳出循环
				}
				currentCount[word2]--; // 使用当前单词
				if (j == wordCountTotal - 1) {
					result.push_back(i); // 如果所有单词都用完，记录起始索引
				}
			}
		}
		return result;
    }
};


/*
滑动窗口法

核心思想：使用两个指针维护一个窗口，窗口内的字符串与目标字符串匹配。
起点数量与单词长度相同，因此我们可以从 0 到 wordLen - 1 的每个起点开始滑动窗口。
每次移动右指针时，移动一个单词的长度，检查当前窗口内的单词是否在目标单词列表中。
用两个HashMap，一个存储目标单词的频率，一个存储当前窗口内的单词频次。
如果当前窗口内的单词频率超过目标频率，移动左指针一个单词的长度缩小窗口，直到频次匹配。

*/ 
class Solution30_Plus {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};

		// 1. 获取字符串长度、单词长度、单词数量和总长度
        int sLen = s.length();
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

		// 2. 如果总长度大于字符串长度，直接返回空结果
        if (sLen < totalLen) return {};

		// 3. 统计目标单词的频率
        unordered_map<string, int> targetCount;
        for (const string& word : words) {
            targetCount[word]++;
        }

		// 4. 初始化结果向量
        vector<int> res;

		// 5. 遍历每个可能的起始位置
        for (int i = 0; i < wordLen; ++i) {
            int left = i;      // 窗口左边界
            int count = 0;     // 当前窗口内匹配的单词数量
            unordered_map<string, int> windowCount; // 当前窗口的单词频率

            // 6. 右边界每次步进 wordLen
            for (int right = i; right <= sLen - wordLen; right += wordLen) {
                // 截取当前单词
                string curWord = s.substr(right, wordLen);

                // 如果当前单词在目标列表中
                if (targetCount.find(curWord) != targetCount.end()) {
                    windowCount[curWord]++;
                    count++;

					// 如果当前单词的数量超过目标数量，移动左边界
                    while (windowCount[curWord] > targetCount[curWord]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // 如果窗口内单词数量刚好等于目标数量，说明找到了一个解
                    if (count == wordCount) {
                        res.push_back(left);
                        // 找到后，左边界继续向右移动一个单词，准备寻找下一个
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
                else {
                    // 如果当前单词不在目标列表中，直接清空窗口，重置左边界
                    windowCount.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};




//int main() {
//	Solution30_Plus sol;
//	string s = "barfoothefoobarman";
//	vector<string> words = { "foo", "bar" };
//	vector<int> result = sol.findSubstring(s, words);
//
//	cout << "Starting indices of concatenated substrings: ";
//	for (int index : result) {
//		cout << index << " ";
//	}
//	cout << endl;
//	return 0;
//}