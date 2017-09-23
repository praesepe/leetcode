class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s1;
        string s2;

        while (head != NULL) {
            s1 = s1 + to_string(head->val);
            s2 = to_string(head->val) + s2;
            head = head->next;
        }

        return s1 == s2;
    }
};

