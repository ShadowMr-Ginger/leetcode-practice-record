#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution3683 {
public:
    int earliestTime(vector<int>& startTime, vector<int>& duration) {
        int n = startTime.size();
        int ans = INT_MAX;
        // 1. 每个任务的完成时间是 startTime[i] + duration[i]，取最小值
        for (int i = 0;i < n;i++) {
            ans = min(ans, startTime[i] + duration[i]);
        }
        return ans;
    }

private:
};

//int main() {
//	Solution3683 solution;
//	vector<int> startTime = {1, 2, 3};
//	vector<int> duration = {2, 1, 4};
//	cout << solution.earliestTime(startTime, duration) << endl;
//	return 0;
//}
