
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。


示例 1：


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <array>
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// 方法一：递归法，时间复杂度O(n)，空间复杂度O(h)，h为树的高度

class Solution114 {
public:
    void myFlatten(TreeNode* root, TreeNode* pre) {
        TreeNode* root1 = root;
        TreeNode* end_node = root;
        while (root1 != nullptr) {
            if (root1->left != nullptr) {
                myFlatten(root1->left, root1);
                root1->left = nullptr;
            }
            else {
                end_node = root1;
                root1 = root1->right;
            }
        }
        if (pre != nullptr) {
            end_node->right = pre->right;
            pre->right = root;
        }
    }
    void flatten(TreeNode* root) {
        myFlatten(root, nullptr);
    }
};

// 方法二: 迭代法，时间复杂度O(n)，空间复杂度O(1) 这个方法更巧妙
class Solution114_PLUS {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // 1. 找到左子树的最右节点（前驱节点）
                TreeNode* predecessor = curr->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }

                // 2. 将当前的右子树挂到前驱节点的 right 上
                predecessor->right = curr->right;

                // 3. 将左子树移到右边
                curr->right = curr->left;

                // 4. 【核心修复】必须将 left 置为 nullptr，否则会导致内存泄漏或循环引用
                curr->left = nullptr;
            }
            // 5. 继续处理下一个节点
            curr = curr->right;
        }
    }
};


//
//
//int main() {
//	Solution114 solution;
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	//root->right = new TreeNode(5);
//	root->left->left = new TreeNode(3);
//	//root->left->right = new TreeNode(4);
//	//root->right->right = new TreeNode(6);
//	solution.flatten(root);
//	// 输出展开后的链表
//	TreeNode* current = root;
//	while (current != nullptr) {
//		cout << current->val << " ";
//		current = current->right;
//	}
//	cout << endl;
//	return 0;
//}