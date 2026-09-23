#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 表结构：Activity(user_id, session_id, activity_date, activity_type)
struct ActivityRow {
	int user_id;
	int session_id;
	string activity_date;
	string activity_type;
};

class Solution1141 {
public:
	// 统计 2019-07-27 之前 30 天内的活跃用户数（按 user_id 去重）
	int activeUsers(vector<ActivityRow>& activity) {
		// 区间两端均含：[2019-06-28, 2019-07-27]
		string left = "2019-06-28";
		string right = "2019-07-27";
		unordered_set<int> users;
		// 1. 按日期过滤，日期格式统一，直接按字典序比较即可
		for (auto& row : activity) {
			if (row.activity_date >= left && row.activity_date <= right) {
				users.insert(row.user_id);
			}
		}
		return (int)users.size();
	}
};

//int main() {
//	Solution1141 solution;
//	vector<ActivityRow> activity = {
//		{1, 1, "2019-07-20", "open_session"},
//		{1, 1, "2019-07-25", "scroll_down"},
//		{1, 1, "2019-07-25", "end_session"},
//		{2, 4, "2019-07-26", "open_session"},
//		{2, 4, "2019-07-26", "send_message"},
//		{2, 4, "2019-07-26", "end_session"},
//		{3, 2, "2019-06-25", "open_session"},
//		{3, 2, "2019-06-25", "end_session"},
//		{4, 3, "2019-06-19", "open_session"},
//		{4, 3, "2019-06-19", "scroll_down"},
//		{4, 3, "2019-06-19", "end_session"},
//	};
//	cout << solution.activeUsers(activity) << endl;
//	return 0;
//}
