/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *current, *next, *previous=NULL;
    
    current = head;
    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    return previous;
}
