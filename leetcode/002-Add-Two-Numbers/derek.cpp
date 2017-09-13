class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        int carry = 0, sum;
        while (l1 != NULL || l2!= NULL) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        if (carry > 0) {
            p->next = new ListNode(carry);
            p = p->next;
        }

        return dummy.next;
    }
};
