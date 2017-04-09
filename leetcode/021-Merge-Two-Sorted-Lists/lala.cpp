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
		ListNode* result = NULL, *walker = NULL, *p1 = l1, *p2 = l2;

		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				if (!result) {
					walker = result = p1;
				} else {
					walker->next = p1;
					walker = walker->next;
				}
				p1 = p1->next;
			} else {
				if (!result) {
					walker = result = p2;
				} else {
					walker->next = p2;
					walker = walker->next;
				}
				p2 = p2->next;
			}
		}

		if (result) {
			walker->next = p1 ? p1 : p2;
		}

		return result ? result : l1 ? l1 : l2;
	}
};
