#include <iostream>
#include <vector>
using namespace std;

class Solution1870 {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        // 前 n-1 段每段至少 1 小时，总时长必须严格大于 n-1
        if (hour <= n - 1) return -1;
        // 二分答案：最小可行速度
        int left = 1, right = 1e7;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canArrive(dist, hour, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    // 判断以 speed 行驶能否在 hour 内到达
    bool canArrive(vector<int>& dist, double hour, int speed) {
        int n = dist.size();
        double total = 0;
        // 前 n-1 段必须整点发车，时间向上取整；最后一段按实际耗时计算
        for (int i = 0;i < n - 1;i++) {
            total += (dist[i] + speed - 1) / speed;
        }
        total += (double)dist[n - 1] / speed;
        return total <= hour;
    }
};

//int main() {
//	Solution1870 s;
//	vector<int> dist1 = {1, 3, 2};
//	cout << s.minSpeedOnTime(dist1, 6) << endl;
//	vector<int> dist2 = {1, 3, 2};
//	cout << s.minSpeedOnTime(dist2, 2.7) << endl;
//	vector<int> dist3 = {1, 3, 2};
//	cout << s.minSpeedOnTime(dist3, 1.9) << endl;
//	return 0;
//}
