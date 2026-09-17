/*
49. 字母异位词分组
已解答
中等
相关标签
premium lock icon
相关企业
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。



示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

解释：

在 strs 中没有字符串可以通过重新排列来形成 "bat"。
字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
示例 2:

输入: strs = [""]

输出: [[""]]

示例 3:

输入: strs = ["a"]

输出: [["a"]]



提示：

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <array>
#include <numeric>
using namespace std;

// 排序法
class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string, int> mp;
        int idx = 0;
        for (int i = 0;i < n;i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (mp.count(tmp)) {
                ans[mp[tmp]].push_back(strs[i]);
            }
            else {
                mp[tmp] = idx;
                idx++;
                vector<string> new_vec;
                new_vec.push_back(strs[i]);
                ans.push_back(new_vec);
            }
        }


        return ans;
    }
};

// 计数法，更高效的哈希方法，避免排序，但是需要自定义哈希函数
class Solution49_PLUS {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. 用 Lambda 定义哈希逻辑：通过位运算和异或混合 26 个字母的频次
        auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
                });
            };

        // 2. 使用 decltype 推导 Lambda 类型，并将 arrayHash 传入构造函数
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);

        for (const auto& str : strs) {
            array<int, 26> count{ 0 };
            for (char c : str) {
                count[c - 'a']++;
            }
            mp[count].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(move(pair.second));
        }
        return ans;
    }
};





//int main() {
//	Solution49 solution;
//	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<vector<string>> ans = solution.groupAnagrams(strs);
//	for (auto& group : ans) {
//		cout << "[";
//		for (auto& str : group) {
//			cout << str << ",";
//		}
//		cout << "]" << endl;
//	}
//	return 0;
//}
//
//











