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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0), *previous = dummy;

		dummy->next = head;
		for (ListNode* current = head; current != NULL; current = current->next) {
			if (val == current->val) {
				ListNode* next = current->next;
				delete current;

				current = previous;
				current->next = next;
			} else {
				previous = current;
			}
		}

		return dummy->next;
	}
};
