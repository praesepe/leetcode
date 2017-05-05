class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *current = head;
        while( l1 || l2 || carry){
            // calculate sum and the new carry
            int sum = (l1 ? l1->val :  0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            current->next = (carry == 1) ? new ListNode(sum % 10) : new ListNode(sum);

            // move to next
            current = current->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
};