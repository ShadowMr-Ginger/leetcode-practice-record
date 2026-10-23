#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution2074 {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        int group_size = 1;
        // 逐组处理，组编号从 1 开始递增
        while (prev->next != nullptr) {
            ListNode* cur = prev->next;
            // 1. 统计本组实际长度（可能不足 group_size）
            int len = 0;
            while (len < group_size && cur != nullptr) {
                cur = cur->next;
                len++;
            }
            // 2. 长度为偶数则反转本组
            if (len % 2 == 0) {
                ListNode* tail = prev->next;
                ListNode* new_head = nullptr;
                cur = prev->next;
                // 3. 头插法反转 len 个节点
                for (int i = 0;i < len;i++) {
                    ListNode* nxt = cur->next;
                    cur->next = new_head;
                    new_head = cur;
                    cur = nxt;
                }
                prev->next = new_head;
                tail->next = cur;
                prev = tail;
            } else {
                // 4. 奇数长度组不反转，直接前进
                for (int i = 0;i < len;i++) {
                    prev = prev->next;
                }
            }
            group_size++;
        }
        return dummy->next;
    }
};

//int main() {
//	ListNode* head = new ListNode(5, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(9, new ListNode(1, new ListNode(7, new ListNode(3, new ListNode(8, new ListNode(4))))))))));
//	Solution2074 sol;
//	ListNode* res = sol.reverseEvenLengthGroups(head);
//	while (res != nullptr) {
//		cout << res->val << " ";
//		res = res->next;
//	}
//	return 0;
//}
