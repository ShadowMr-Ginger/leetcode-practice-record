#include <iostream>
#include <vector>

using namespace std;

class Solution2798 {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        // 统计工作时长达到 target 的员工数
        for (int i = 0;i < hours.size();i++) {
            if (hours[i] >= target) {
                count++;
            }
        }
        return count;
    }
};

//int main() {
//	Solution2798 solution;
//	vector<int> hours = {0, 1, 2, 3, 4};
//	int target = 2;
//	cout << solution.numberOfEmployeesWhoMetTarget(hours, target) << endl;
//	return 0;
//}
