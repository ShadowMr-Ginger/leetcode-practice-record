#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution103 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);
		bool left_to_right = true;
		while (!q.empty()) {
			int n = q.size();
			vector<int> level(n);
			for (int i = 0;i < n;i++) {
				TreeNode* node = q.front();
				q.pop();
				// 按当前方向写入对应下标，实现之字形
				int index = left_to_right ? i : n - 1 - i;
				level[index] = node->val;
				if (node->left != nullptr) {
					q.push(node->left);
				}
				if (node->right != nullptr) {
					q.push(node->right);
				}
			}
			ans.push_back(level);
			// 每层结束后翻转方向
			left_to_right = !left_to_right;
		}
		return ans;
	}
};

//int main() {
//	Solution103 s;
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//	vector<vector<int>> ans = s.zigzagLevelOrder(root);
//	for (auto& level : ans) {
//		for (auto& x : level) {
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
