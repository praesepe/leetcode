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
		ListNode* result = NULL, *p = NULL, *c, *cn, *cnn, *walker;

		//    walker
		// p->c->cn->cnn
		//
		//           walker
		// p->cn->c->cnn
		walker = head;
		while (walker) {
			c = walker;
			cn = c->next;
			cnn = cn ? cn->next : NULL;

			//  c->cnn
			// cn
			c->next = cnn;

			// cn->c->cnn
			if (cn) {
				cn->next = c;
			}

			// p->cn->c->cnn
			if (p) {
				p->next = cn ? cn : c;
			}

			//
			if (!result) {
				result = cn ? cn : c;
			}

			p = c;
			walker = cnn;
		}

		return result;
	}
};
