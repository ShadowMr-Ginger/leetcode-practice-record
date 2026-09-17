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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans_dummy = new ListNode(0);
        ListNode* tmp = ans_dummy;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                tmp->next = list2;
                tmp = tmp->next;
                list2 = list2->next;
            }
            else if (list2 == nullptr) {
                tmp->next = list1;
                tmp = tmp->next;
                list1 = list1->next;
            }
            else {
                if (list1->val < list2->val) {
                    tmp->next = list1;
                    tmp = tmp->next;
                    list1 = list1->next;
                }
                else {
                    tmp->next = list2;
                    tmp = tmp->next;
                    list2 = list2->next;
                }
            }
        }
        ListNode* ans = ans_dummy->next;
        delete ans_dummy;
        return ans;
    }
};


//int main() {
//	Solution21 solution;
//	ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
//	ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
//	ListNode* mergedList = solution.mergeTwoLists(list1, list2);
//	// Print the merged list
//	while (mergedList != nullptr) {
//		cout << mergedList->val << " ";
//		mergedList = mergedList->next;
//	}
//	cout << endl;
//	// Clean up memory
//	delete list1->next->next; // Delete node with value 4
//	delete list1->next;       // Delete node with value 2
//	delete list1;             // Delete node with value 1
//	//delete list2->next->next; // Delete node with value 4
//	//delete list2->next;       // Delete node with value 3
//	//delete list2;             // Delete node with value 1
//	return 0;
//}