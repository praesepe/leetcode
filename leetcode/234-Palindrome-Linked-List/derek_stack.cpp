class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // find middle node
        stack<ListNode*> st;
        ListNode *slow = head, *fast = head;
        st.push(slow);
        while (fast->next != NULL && fast->next->next != NULL) {
            // move forward
            slow = slow->next;
            fast = fast->next->next;
            // push slow to stack
            st.push(slow);
        }

        // if the number of list nodes is odd number, skip the middle node
        if (fast->next == NULL) {
            st.pop();
        }

        // compare each node
        ListNode *p, *q = slow->next;
        while (q != NULL) {
            ListNode* p = st.top();
            st.pop();
            if (p->val != q->val) {
                return false;
            }
            q = q->next;
        }

        return true;
    }
};

