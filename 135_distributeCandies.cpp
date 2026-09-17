#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution135 {
public:
    int candy(vector<int>& ratings) {
        // 边界处理
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }

        int candies = 1; //初始化给第一个小朋友分到1颗糖
        int increase = 1; // 初始假设升序数为1
        int decrease = 0; // 初始假设降序数为0
        int last_candies = 1; // 初始上次分配的糖果数为1

        for (int i = 1;i < n;i++) {
            if (ratings[i] > ratings[i - 1]) {
                // 升序情况
                decrease = 0; //清除降序累计
                if (last_candies == 1) {
                    // 上次是平序或降序，将升序累积归为1
                    increase = 1;
                }
                increase++;
                last_candies++;
                candies += increase;
                last_candies = increase;
            }
            else if (ratings[i] == ratings[i - 1]) {
                // 平序情况
                increase = 1;
                decrease = 0; //清除降序累计,归至1
                candies++;
                last_candies = 1;
            }
            else {
                // 降序情况
                decrease++;
                if (decrease == increase) {
                    //连续降序次数超过连续升序次数，携带升序末尾的最后一个孩子的糖果数上升
                    decrease++;
                }
                candies += decrease;
                last_candies = 1;
            }
        }
        return candies;
    }
};

//int main() {
//	vector<int> ratings = { 1, 0, 2 };
//	Solution135 sol;
//	int total_candies = sol.candy(ratings);
//	cout << "Total candies needed: " << total_candies << endl;
//	return 0;
//}