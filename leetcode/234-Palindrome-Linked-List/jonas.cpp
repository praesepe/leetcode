ass Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* next = head->next;

        slow->next = NULL;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            // reverse link
            ListNode* prev = slow;
            slow = next;
            next = next->next;
            slow->next = prev;
        }

        if (fast->next) {
            // num nodes is odd
            next = next->next;
        }
        while (slow) {
            if (slow->val != next->val) {
                return false;
            }
            slow = slow->next;
            next = next->next;
        }
        return true;
    }
};
