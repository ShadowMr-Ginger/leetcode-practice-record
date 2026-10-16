#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution3570 {
public:
    // 输入：book_id[i] 与 quantity[i] 表示第 i 本书的编号和总册数
    // borrowed_book_id 中记录的是所有“已借出且未归还”的书记录（可含重复）
    vector<int> findBooks(vector<int>& book_id, vector<int>& quantity, vector<int>& borrowed_book_id) {
        // 1. 统计每本书当前被借出未还的册数
        unordered_map<int, int> borrowed_cnt;
        for (int id : borrowed_book_id) {
            borrowed_cnt[id]++;
        }
        // 2. 总册数等于未归还册数的书即没有可用副本
        vector<int> res;
        int n = book_id.size();
        for (int i = 0;i < n;i++) {
            if (quantity[i] == borrowed_cnt[book_id[i]]) {
                res.push_back(book_id[i]);
            }
        }
        // 3. 按编号升序输出
        sort(res.begin(), res.end());
        return res;
    }
};

//int main() {
//	Solution3570 solution;
//	vector<int> book_id = {1, 2, 3, 4};
//	vector<int> quantity = {2, 3, 1, 6};
//	vector<int> borrowed_book_id = {1, 2, 1, 3, 2, 2};
//	vector<int> res = solution.findBooks(book_id, quantity, borrowed_book_id);
//	for (int id : res) {
//		cout << id << " ";
//	}
//	cout << endl;
//	return 0;
//}
