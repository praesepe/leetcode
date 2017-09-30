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
    bool check(ListNode* &head_ptr, ListNode* tail_ptr) {
        if (!tail_ptr) return true;
        if (head_ptr == tail_ptr) return true;

        bool result = this->check(head_ptr, tail_ptr->next) && head_ptr->val == tail_ptr->val;
        if (!result) return false;

        head_ptr = head_ptr->next;
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        return this->check(head, head->next);
    }
};
