#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution42 {
public:
    int trap(vector<int>& height) {
        vector<int> left_wall;
        vector<int> right_wall;
        int len = height.size();
        left_wall.resize(len);
        right_wall.resize(len);

        int total_water = 0;

        int tmp = 0;
        for (int i = 0;i < height.size();i++) {
            if (height[i] > tmp) {
                tmp = height[i];
            }
            left_wall[i] = tmp;
        }
        tmp = 0;
        for (int i = height.size() - 1;i > -1;i--) {
            if (height[i] > tmp) {
                tmp = height[i];
            }
            right_wall[i] = tmp;
        }

        for (int i = 0;i < height.size();i++) {
            int wall_height = 0;
            if (left_wall[i] < right_wall[i]) {
                wall_height = left_wall[i];
            }
            else {
                wall_height = right_wall[i];
            }
            total_water += wall_height - height[i];
        }
        return total_water;
    }
};


//int main() {
//	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//	Solution42 sol;
//	int total_water = sol.trap(height);
//	cout << "Total trapped water: " << total_water << endl;
//	return 0;
//}