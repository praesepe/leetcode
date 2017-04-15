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
private:
    int getValue(ListNode* p) {
        return p ? p->val : 0;
    }

    void listNext(ListNode** p) {
        if (*p) {
            *p = (*p)->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy, *walker, *p1 = l1, *p2 = l2;

		walker = dummy = new ListNode(0);
		int carry = 0;
		while (p1 != NULL || p2 != NULL) {
			int sum = carry + this->getValue(p1) + this->getValue(p2);
			int val = sum % 10;
			carry = sum / 10;

			walker->next = new ListNode(val);
			walker = walker->next;

			this->listNext(&p1);
			this->listNext(&p2);
		}

        if (carry > 0) {
            walker->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
