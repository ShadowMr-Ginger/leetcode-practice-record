#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1487 {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> next_suffix;
        vector<string> answer;

        for (const string& name : names) {
            // 1. 没出现过，直接占用，并从 1 开始记录候选后缀
            if (next_suffix.find(name) == next_suffix.end()) {
                next_suffix[name] = 1;
                answer.push_back(name);
                continue;
            }

            // 2. 出现过，从记录的后缀开始找最小可用名字
            int k = next_suffix[name];
            string candidate = name + "(" + to_string(k) + ")";
            while (next_suffix.find(candidate) != next_suffix.end()) {
                k++;
                candidate = name + "(" + to_string(k) + ")";
            }

            // 3. 占用新名字，并更新原名字下次应尝试的后缀
            next_suffix[name] = k + 1;
            next_suffix[candidate] = 1;
            answer.push_back(candidate);
        }

        return answer;
    }
};

//int main() {
//	Solution1487 solution;
//	vector<string> names = {"gta", "gta(1)", "gta", "avalon"};
//	vector<string> ans = solution.getFolderNames(names);
//	for (const string& s : ans) {
//		cout << s << " ";
//	}
//	cout << endl;
//	return 0;
//}
