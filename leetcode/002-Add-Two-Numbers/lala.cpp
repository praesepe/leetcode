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
        ListNode *result = NULL, *walker = NULL, *p1 = l1, *p2 = l2;

		int carry = 0;
		while (p1 != NULL || p2 != NULL) {
			int sum = carry + getValue(p1) + getValue(p2);
			int val = sum % 10;
			carry = sum / 10;

			if (!walker) {
				result = walker = new ListNode(val);
			} else {
				walker->next = new ListNode(val);
				walker = walker->next;
			}

			listNext(&p1);
			listNext(&p2);
		}

        if (carry > 0) {
            walker->next = new ListNode(carry);
        }

        return result;
    }
};
