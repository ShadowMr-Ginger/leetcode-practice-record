#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1280 {
public:
	vector<vector<string>> findStudents(vector<vector<string>>& students, vector<vector<string>>& subjects, vector<vector<string>>& examinations) {
		// 1. 统计每个学生在每门科目的考试次数
		unordered_map<string, unordered_map<string, int>> cnt;
		for (auto& e : examinations) {
			cnt[e[0]][e[1]]++;
		}
		// 2. 按学生表顺序 × 科目表顺序生成结果，缺失补 0
		vector<vector<string>> res;
		for (auto& s : students) {
			for (auto& sub : subjects) {
				int c = 0;
				if (cnt.count(s[0]) && cnt[s[0]].count(sub[0])) {
					c = cnt[s[0]][sub[0]];
				}
				res.push_back({s[0], s[1], sub[0], to_string(c)});
			}
		}
		return res;
	}
};

//int main() {
//	Solution1280 sol;
//	vector<vector<string>> students = {{"1","Alice"},{"2","Bob"},{"13","Alex"},{"6","John"}};
//	vector<vector<string>> subjects = {{"Math"},{"Physics"},{"Programming"}};
//	vector<vector<string>> examinations = {{"1","Math"},{"1","Physics"},{"1","Programming"},{"2","Programming"},{"1","Physics"},{"1","Math"},{"13","Math"},{"13","Programming"},{"13","Physics"},{"2","Math"},{"1","Math"}};
//	vector<vector<string>> res = sol.findStudents(students, subjects, examinations);
//	for (auto& row : res) {
//		for (auto& x : row) {
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
