
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;



struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* next_pt = l3;
        bool carry_over = false;
        while (!(l1 == nullptr && l2 == nullptr && !carry_over)) {
            int next_int1 = 0;
            int next_int2 = 0;
            if (l1 != nullptr) {
                next_int1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                next_int2 = l2->val;
                l2 = l2->next;
            }
            int next_int3 = next_int1 + next_int2;
            if (carry_over) {
                next_int3++;
                carry_over = false;
            }
            if (next_int3 >= 10) {
                carry_over = true;
                next_int3 = next_int3 % 10;
            }
            next_pt->next = new ListNode(next_int3);
            next_pt = next_pt->next;
        }
        l3 = l3->next;
        return l3;
    }
};

//int main() {
//	// 创建两个链表: 2 -> 4 -> 3 和 5 -> 6 -> 4
//	ListNode* l1 = new ListNode(9);
//	ListNode* l2 = new ListNode(1);
//	l2->next = new ListNode(9);
//    l2->next->next = new ListNode(9);
//    l2->next->next->next = new ListNode(9);
//    l2->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next->next->next->next->next = new ListNode(9);
//    l2->next->next->next->next->next->next->next->next->next->next = new ListNode(9);
//	Solution2 solution;
//	ListNode* result = solution.addTwoNumbers(l1, l2);
//	// 输出结果链表
//	while (result != nullptr) {
//		cout << result->val;
//		if (result->next != nullptr) {
//			cout << " -> ";
//		}
//		result = result->next;
//	}
//	cout << endl;
//	// 注意：这里没有释放内存，为了简化示例
//	return 0;
//}