#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution1912 {
public:
    Solution1912(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            unrented_[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto it = unrented_.find(movie);
        if (it == unrented_.end()) return ans;

        // 未租集合本身按 (价格, 商店) 升序，只取前 5 个
        int cnt = 0;
        for (const auto& p : it->second) {
            ans.push_back(p.second);
            if (++cnt == 5) break;
        }
        return ans;
    }

    void rent(int shop, int movie, int price) {
        unrented_[movie].erase({price, shop});
        rented_.insert({price, shop, movie});
    }

    void drop(int shop, int movie, int price) {
        rented_.erase({price, shop, movie});
        unrented_[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (const auto& t : rented_) {
            ans.push_back({get<1>(t), get<2>(t)});
            if (++cnt == 5) break;
        }
        return ans;
    }

private:
    // 未租出：按电影分组，组内按 (价格, 商店) 排序
    unordered_map<int, set<pair<int,int>>> unrented_;
    // 已租出：按 (价格, 商店, 电影) 排序，便于 report 取前 5
    set<tuple<int,int,int>> rented_;
};

//int main() {
//	vector<vector<int>> entries = {{0,1,5},{0,2,6},{0,3,7},{1,1,4},{1,2,7},{2,1,5}};
//	Solution1912 obj(3, entries);
//	vector<int> r1 = obj.search(1);
//	for (int x : r1) cout << x << ' ';
//	cout << '\n';
//	obj.rent(0,1,5);
//	obj.rent(1,2,7);
//	vector<vector<int>> rep = obj.report();
//	for (auto& row : rep) cout << row[0] << ',' << row[1] << ' ';
//	cout << '\n';
//	obj.drop(1,2,7);
//	vector<int> r2 = obj.search(1);
//	for (int x : r2) cout << x << ' ';
//	cout << '\n';
//	return 0;
//}
