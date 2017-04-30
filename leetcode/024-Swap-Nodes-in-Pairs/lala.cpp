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
	ListNode* swapPairs(ListNode* head) {
		if (!head) {
			return NULL;
		}

		ListNode *previous, *current, *current_next;
		ListNode *result = head->next;

		current = previous = head;
		while (current && current->next) {
			current_next = current->next;

			previous->next = current_next;
			current->next = current_next->next;
			current_next->next = current;

			previous = current;
			current = current->next;
		}

		return result ? result : head;
	}
};
