#include <stdio.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result, *walker, *dummy, *p1 = l1, *p2 = l2;

        walker = dummy = new ListNode(0);
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                walker->next = p1;
                walker = walker->next;
                p1 = p1->next;
            } else {
                walker->next = p2;
                walker = walker->next;
                p2 = p2->next;
            }
        }
        walker->next = p1 ? p1 : p2;

        result = dummy->next;
        return result? result : l1 ? l1 : l2;
    }
};
