class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *one = head;
        ListNode *two = head;

        while (one && two) {
            one = one->next;
            two = two->next ? two->next->next : two->next;

            if (one && two && one == two) {
                return true;
            }
        }
        return false;
    }
};
