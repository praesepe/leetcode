class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        // find middle node
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // after reverse the right part of list, we concatenate right
        // part with left part. if we don't care, we don't have to do
        // assignment, reverse is enough
        slow->next = reverse(slow->next);

        // compare each node
        ListNode* p = head;
        ListNode* q = slow->next;
        while (q != NULL) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *p = NULL, *q = head, *r;
        while (q != NULL) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};

