#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Sales 表的一行
struct Sale {
    int sale_id;
    int product_id;
    int year;
    int quantity;
    int price;
};

// Product 表的一行
struct Product {
    int product_id;
    string product_name;
};

class Solution1068 {
public:
    // 模拟 SQL：SELECT product_name, year, price FROM Sales JOIN Product USING(product_id)
    vector<vector<string>> productSalesAnalysis(vector<Sale>& sales, vector<Product>& products) {
        // 1. 建 product_id 到 product_name 的哈希索引
        unordered_map<int, string> id_to_name;
        for (int i = 0;i < (int)products.size();i++) {
            id_to_name[products[i].product_id] = products[i].product_name;
        }

        // 2. 按 Sales 表顺序做内连接，拼出 (product_name, year, price)
        vector<vector<string>> result;
        for (int i = 0;i < (int)sales.size();i++) {
            if (id_to_name.count(sales[i].product_id)) {
                result.push_back({
                    id_to_name[sales[i].product_id],
                    to_string(sales[i].year),
                    to_string(sales[i].price)
                });
            }
        }
        return result;
    }
};

//int main() {
//	Solution1068 sol;
//	vector<Sale> sales = {{1, 100, 2008, 10, 5000}, {2, 100, 2009, 12, 5000}, {7, 200, 2011, 15, 9000}};
//	vector<Product> products = {{100, "Nokia"}, {200, "Apple"}, {300, "Samsung"}};
//	vector<vector<string>> res = sol.productSalesAnalysis(sales, products);
//	for (int i = 0;i < (int)res.size();i++) {
//		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
//	}
//	return 0;
//}
