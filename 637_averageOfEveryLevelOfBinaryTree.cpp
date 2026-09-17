#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// 广度优先搜索 BFS，时间复杂度O(n)，空间复杂度O(n)
class Solution637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) {
            return ans;
        }
        int level_size = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double current_level_sum = 0;
            for (int i = 0; i < level_size; i++) {
                current_level_sum += q.front()->val;
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            current_level_sum /= level_size;
            ans.push_back(current_level_sum);
            level_size = q.size();
        }
        return ans;
    }
};


// 深度优先搜索 DFS，时间复杂度O(n)，空间复杂度O(h)，h为树的高度

class Solution637_DFS {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        auto counts = vector<int>();
        auto sums = vector<double>();
        dfs(root, 0, counts, sums);
        auto averages = vector<double>();
        int size = sums.size();
        for (int i = 0; i < size; i++) {
            averages.push_back(sums[i] / counts[i]);
        }
        return averages;
    }

    void dfs(TreeNode* root, int level, vector<int>& counts, vector<double>& sums) {
        if (root == nullptr) {
            return;
        }
        if (level < sums.size()) {
            sums[level] += root->val;
            counts[level] += 1;
        }
        else {
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
};



//int main() {
//	Solution637 solution;
//	TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
//	vector<double> averages = solution.averageOfLevels(root);
//	cout << "Average of each level: ";
//	for (double avg : averages) {
//		cout << avg << " ";
//	}
//	cout << endl; // Output: 3 14.5 11
//	return 0;
//}