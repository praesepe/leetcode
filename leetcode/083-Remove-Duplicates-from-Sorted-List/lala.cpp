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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return NULL;

		ListNode *previous = head, *walker = head->next;
		while (walker) {
			if (walker->val == previous->val) {
				ListNode* deleted = walker;

				previous->next = walker->next;
				walker = walker->next;

				delete deleted;
			} else {
				previous = walker;
				walker = walker->next;
			}
		}

		return head;
	}
};
