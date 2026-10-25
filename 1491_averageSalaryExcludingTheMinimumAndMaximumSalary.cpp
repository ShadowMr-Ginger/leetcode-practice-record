#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution1491 {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        // 找到最小值和最大值
        int min_salary = *min_element(salary.begin(), salary.end());
        int max_salary = *max_element(salary.begin(), salary.end());
        // 总和减去最小值和最大值
        int sum = accumulate(salary.begin(), salary.end(), 0);
        return (double)(sum - min_salary - max_salary) / (n - 2);
    }
};

//int main() {
//	Solution1491 solution;
//	vector<int> salary = {4000, 3000, 1000, 2000};
//	cout << solution.average(salary) << endl;
//	vector<int> salary2 = {1000, 2000, 3000};
//	cout << solution.average(salary2) << endl;
//	return 0;
//}
