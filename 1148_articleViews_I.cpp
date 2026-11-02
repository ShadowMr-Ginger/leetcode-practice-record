#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution1148 {
public:
    vector<int> articleViews(vector<int>& author_id, vector<int>& viewer_id) {
        int n = author_id.size();
        // 1. 找出浏览过自己文章的作者，去重
        unordered_set<int> seen;
        for (int i = 0;i < n;i++) {
            if (author_id[i] == viewer_id[i]) {
                seen.insert(author_id[i]);
            }
        }
        // 2. 按 id 升序返回
        vector<int> res(seen.begin(), seen.end());
        sort(res.begin(), res.end());
        return res;
    }
};

//int main() {
//	Solution1148 solution;
//	vector<int> author_id = {3, 3, 7, 7, 7, 4, 4};
//	vector<int> viewer_id = {5, 6, 7, 6, 1, 4, 3};
//	vector<int> res = solution.articleViews(author_id, viewer_id);
//	for (int i = 0;i < (int)res.size();i++) {
//		cout << res[i] << endl;
//	}
//	return 0;
//}
