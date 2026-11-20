#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution1174 {
public:
    double immediate_percentage(vector<vector<int>>& delivery) {
        unordered_map<int, int> first_order_date;
        unordered_map<int, bool> is_immediate;

        // 1. 统计每个顾客的最早下单日期，以及最早订单是否即时送达
        for (int i = 0;i < (int)delivery.size();i++) {
            int customer_id = delivery[i][1];
            int order_date = delivery[i][2];
            int pref_date = delivery[i][3];

            if (first_order_date.find(customer_id) == first_order_date.end() || order_date < first_order_date[customer_id]) {
                first_order_date[customer_id] = order_date;
                is_immediate[customer_id] = (order_date == pref_date);
            } else if (order_date == first_order_date[customer_id] && order_date == pref_date) {
                // 同一最早日期有多条记录时，只要有一条是即时单即可
                is_immediate[customer_id] = true;
            }
        }

        int total_customers = (int)first_order_date.size();
        if (total_customers == 0) {
            return 0.0;
        }

        // 2. 统计首单即时的顾客数
        int immediate_cnt = 0;
        for (auto it = is_immediate.begin(); it != is_immediate.end(); it++) {
            if (it->second) {
                immediate_cnt++;
            }
        }

        // 3. 计算百分比并保留两位小数
        double percentage = 100.0 * immediate_cnt / total_customers;
        return round(percentage * 100) / 100;
    }
};

//int main() {
//	Solution1174 solution;
//	vector<vector<int>> delivery = {{1,1,20190801,20190801},{2,2,20190801,20190802},{3,1,20190802,20190802},{4,3,20190805,20190805},{5,4,20190805,20190805},{6,2,20190810,20190810}};
//	cout << solution.immediate_percentage(delivery) << endl;
//	return 0;
//}
