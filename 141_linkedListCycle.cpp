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


class Solution141 {
public:
    bool hasCycle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // 快慢指针
        ListNode* pt_fast = head->next;
        ListNode* pt_slow = head;
        bool ans = true;

        while (pt_fast != pt_slow) {
            if (pt_fast->next == nullptr || pt_fast->next->next == nullptr) {
                return false;
            }
            pt_fast = pt_fast->next->next;
            pt_slow = pt_slow->next;
        }

        return ans;
    }
};

//int main() {
//	// 创建一个有环链表: 1 -> 2 -> 3 -> 4 -> 2 (环)
//	ListNode* head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = head->next; // 创建环
//	Solution141 solution;
//	bool hasCycle = solution.hasCycle(head);
//	if (hasCycle) {
//		cout << "The linked list has a cycle." << endl;
//	}
//	else {
//		cout << "The linked list does not have a cycle." << endl;
//	}
//	// 注意：这里没有释放内存，因为链表有环，释放会导致无限循环
//	return 0;
//}