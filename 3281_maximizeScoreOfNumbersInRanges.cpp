#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution3281 {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        // 二分可能的最小间隔
        long long lo = 1, hi = 0;
        for (int i = 0;i < n;i++) hi = max(hi, (long long)start[i] + d);
        hi -= start[0];

        if (!check(start, d, 1)) return 0;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (check(start, d, mid)) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }

private:
    // 贪心取每个位置能选的最小值，判断间隔能否都不小于 score
    bool check(const vector<int>& start, int d, long long score) {
        int n = start.size();
        long long prev = start[0];
        for (int i = 1;i < n;i++) {
            long long lower = max((long long)start[i], prev + score);
            if (lower > (long long)start[i] + d) return false;
            prev = lower;
        }
        return true;
    }
};

//int main() {
//	vector<int> start = {2,4,7};
//	int d = 4;
//	Solution3281 sol;
//	cout << sol.maxPossibleScore(start, d) << endl;
//	return 0;
//}
