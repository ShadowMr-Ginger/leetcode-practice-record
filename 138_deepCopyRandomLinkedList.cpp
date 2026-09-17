/*

给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;




class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



// 原做法：复制链表的每个节点，先复制一轮，然后将复制链表插入原链表中，再对random指针进行后移一位，最后将新增出来的Node*分离出来。时间复杂度O(n)，空间复杂度O(1)
class Solution138 {
public:
    Node* copyRandomList(Node* head) {

        Node* head_new = new Node(0);
        Node* iter = head;
        Node* iter_new = head_new;

        // 拷贝一轮
        while (iter != nullptr) {
            iter_new->next = new Node(iter->val);
            iter_new = iter_new->next;
            iter_new->random = iter->random;
            iter = iter->next;
        }

        head_new = head_new->next;
        if (head_new == nullptr) {
            return head_new;
        }

        // 将复制链表插入原链表
        iter = head;
        iter_new = head_new;

        while (iter != nullptr) {
            Node* tmp1 = iter->next;
            Node* tmp2 = iter_new->next;
            iter->next = iter_new;
            iter_new->next = tmp1;
            iter = tmp1;
            iter_new = tmp2;
        }

        // 对random pointer进行后移一位
        iter_new = head;
        while (iter_new != nullptr) {
            iter_new = iter_new->next;
            if (iter_new->random != NULL) {
                iter_new->random = iter_new->random->next;
            }
            iter_new = iter_new->next;
        }

        // 将新增出来的Node*分离出来
        iter = head;
        iter_new = head_new;
        while (iter_new->next != nullptr) {
            iter->next = iter_new->next;
            iter = iter->next;
            iter_new->next = iter->next;
            iter_new = iter_new->next;
        }
        iter->next = iter_new->next;

        // 返回新链表
        return head_new;
    }
};


// AI优化后的原地拼接方法，,比原来的方法快了大约一倍，时间复杂度O(n)，空间复杂度O(1)
class Solution138_PLUS {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. 第一次遍历：原地拼接 (A -> A' -> B -> B' ...)
        Node* iter = head;
        while (iter) {
            Node* newNode = new Node(iter->val);
            newNode->next = iter->next;
            iter->next = newNode;
            iter = newNode->next; // 跳到下一个原节点
        }

        // 2. 第二次遍历：修正 random 指针
        iter = head;
        while (iter) {
            Node* copyNode = iter->next;
            if (iter->random) {
                copyNode->random = iter->random->next;
            }
            iter = copyNode->next; // 跳到下一个原节点
        }

        // 3. 第三次遍历：拆分链表（最关键的步骤）
        Node* newHead = head->next;
        iter = head;
        while (iter) {
            Node* copyNode = iter->next;
            Node* nextOrig = copyNode->next; // 暂存下一个原节点

            // 恢复原链表
            iter->next = nextOrig;

            // 推进新链表（注意处理尾部边界）
            copyNode->next = nextOrig ? nextOrig->next : nullptr;

            iter = nextOrig; // 移动到下一个原节点
        }

        return newHead;
    }
};



//int main() {
//	Solution138 solution;
//	Node* head = new Node(7);
//	head->next = new Node(13);
//	head->next->next = new Node(11);
//	head->next->next->next = new Node(10);
//	head->next->next->next->next = new Node(1);
//	head->random = nullptr;
//	head->next->random = head;
//	head->next->next->random = head->next->next->next->next;
//	head->next->next->next->random = head->next;
//	head->next->next->next->next->random = head;
//	Node* copiedListHead = solution.copyRandomList(head);
//	// Print the copied list to verify
//	Node* iter = copiedListHead;
//	while (iter != nullptr) {
//		cout << "Node val: " << iter->val;
//		if (iter->random != nullptr) {
//			cout << ", Random points to: " << iter->random->val << endl;
//		}
//		else {
//			cout << ", Random points to: nullptr" << endl;
//		}
//		iter = iter->next;
//	}
//	return 0;
//}