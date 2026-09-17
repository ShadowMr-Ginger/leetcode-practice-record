#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 边界保护
        int n = gas.size();
        if (n == 0) {
            return -1;
        }

        // 假设从0出发，记录剩余gas的点（允许为负）
        int surplus_gas = 0;

        // 记录亏油最大的点
        int min_gas_p = 0;
        int min_gas = 0 + gas[0] - cost[0];
        for (int i = 0;i < n;i++) {
            surplus_gas = surplus_gas + gas[i] - cost[i];
            if (surplus_gas < min_gas) {
                min_gas_p = i;
                min_gas = surplus_gas;
            }
        }

        // 若剩余油为负，一定不可抵达。
        if (surplus_gas < 0) {
            return -1;
        }
        // 若可抵达，从最大亏油点下一个点出发
        return (min_gas_p + 1) % n;
    }
};

//int main() {
//	vector<int> gas = { 1, 2, 3, 4, 5 };
//	vector<int> cost = { 3, 4, 5, 1, 2 };
//	Solution134 sol;
//	int start_index = sol.canCompleteCircuit(gas, cost);
//	cout << "Start index: " << start_index << endl;
//	return 0;
//}