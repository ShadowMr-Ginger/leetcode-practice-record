#include <vector>
#include <string>

using namespace std;

class Solution2446 {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // 转成分钟数方便比较
        int s1 = toMinutes(event1[0]);
        int e1 = toMinutes(event1[1]);
        int s2 = toMinutes(event2[0]);
        int e2 = toMinutes(event2[1]);
        // 两个区间相交的条件：较晚的开始时间 <= 较早的结束时间
        return max(s1, s2) <= min(e1, e2);
    }

private:
    // 将 "HH:MM" 转换为当天分钟数
    int toMinutes(const string& time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        return h * 60 + m;
    }
};

//int main() {
//	Solution2446 solution;
//	vector<string> event1 = {"01:15", "02:00"};
//	vector<string> event2 = {"02:00", "03:00"};
//	cout << solution.haveConflict(event1, event2) << endl;
//
//	vector<string> event3 = {"01:00", "02:00"};
//	vector<string> event4 = {"01:20", "03:00"};
//	cout << solution.haveConflict(event3, event4) << endl;
//	return 0;
//}
