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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = NULL;

        ListNode* walker = head;
        while (walker) {
            ListNode* tmp = tail;

            tail = walker;
            walker = walker->next;
            tail->next = tmp;
        }

        return tail;
    }
};
