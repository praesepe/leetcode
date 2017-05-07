/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int digit = carry + x + y;
            carry = digit / 10;
            curr->next = new ListNode(digit % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
