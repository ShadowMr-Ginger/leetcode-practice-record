#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1321 {
public:
    vector<vector<string>> restaurantGrowth(vector<vector<string>>& customer) {
        // 1. 按日期聚合当天总消费
        unordered_map<string, long long> day_sum;
        for (auto& row : customer) {
            day_sum[row[2]] += stoll(row[3]);
        }
        // 2. 日期排序（题目保证日期连续且每天都有记录）
        vector<string> dates;
        for (auto& p : day_sum) dates.push_back(p.first);
        sort(dates.begin(), dates.end());
        int n = dates.size();
        // 3. 前缀和 + 长度为 7 的滑动窗口求移动平均
        vector<long long> prefix(n + 1, 0);
        for (int i = 0;i < n;i++) {
            prefix[i + 1] = prefix[i] + day_sum[dates[i]];
        }
        vector<vector<string>> res;
        for (int i = 6;i < n;i++) {
            long long total = prefix[i + 1] - prefix[i - 6];
            // 4. 结果保留两位小数
            res.push_back({dates[i], to_string(total),
                           format_avg(total)});
        }
        return res;
    }

private:
    string format_avg(long long total) {
        // 金额都是整数，直接换算避免浮点误差
        long long avg_x100 = total * 100 / 7;
        string s = to_string(avg_x100 / 100) + ".";
        long long frac = avg_x100 % 100;
        if (frac < 10) s += "0";
        s += to_string(frac);
        return s;
    }
};

//int main() {
//	vector<vector<string>> customer = {
//		{"1", "Jhon", "2019-01-01", "100"},
//		{"2", "Daniel", "2019-01-02", "110"},
//		{"3", "Jade", "2019-01-03", "120"},
//		{"4", "Khaled", "2019-01-04", "130"},
//		{"5", "Winston", "2019-01-05", "110"},
//		{"6", "Elvis", "2019-01-06", "140"},
//		{"7", "Anna", "2019-01-07", "150"},
//		{"8", "Maria", "2019-01-08", "80"},
//		{"9", "Jaze", "2019-01-09", "110"},
//		{"1", "Jhon", "2019-01-10", "130"},
//		{"3", "Jade", "2019-01-10", "150"}
//	};
//	Solution1321 sol;
//	vector<vector<string>> res = sol.restaurantGrowth(customer);
//	for (auto& row : res) {
//		cout << row[0] << " " << row[1] << " " << row[2] << endl;
//	}
//	return 0;
//}
