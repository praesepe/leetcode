#include <stdio.h>
/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode* dummy = new RandomListNode(0), *walker = NULL, *result_walker = NULL;

		// copy link
		walker = head;
		while (walker) {
			RandomListNode* next = walker->next;
			RandomListNode* copy = new RandomListNode(walker->label);

			walker->next = copy;
			walker = copy->next = next;
		}

		// link random
		walker = head;
		while (walker) {
			RandomListNode* copy = walker->next;
			RandomListNode* random = walker->random;

			copy->random = random ? random->next : NULL;
			walker = copy->next;
		}

		// make result
		result_walker = dummy;
		walker = head;
		while (walker) {
			RandomListNode* copy = walker->next;

			// link result
			result_walker = result_walker->next = copy;

			// restore original list
			walker = walker->next = copy->next;
		}

		return dummy->next;
	}
};
