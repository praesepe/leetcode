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
    int get_length(ListNode* head) {
        int result = 0;
        for (ListNode *walker = head; walker != NULL; walker = walker->next) result++;

        return result;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = this->get_length(headA);
        int length_b = this->get_length(headB);

        ListNode* walker_a = headA;
        ListNode* walker_b = headB;

        // find
        while (walker_a && walker_b) {
            if (walker_a == walker_b) {
                return walker_a;
            } else if (length_b > length_a) {
                walker_b = walker_b->next;
                length_b--;
            } else if (length_b < length_a) {
                walker_a = walker_a->next;
                length_a--;
            } else {
                walker_a = walker_a->next;
                walker_b = walker_b->next;
            }
        }

        return NULL;
    }
};
