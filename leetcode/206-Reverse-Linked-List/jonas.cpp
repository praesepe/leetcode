class Solution {
 public:
    ListNode* reverseList(ListNode* head) {
		ListNode* previous = NULL;
		ListNode* next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = previous;
			previous = head;
			head = next;
		}
		return previous;
    }
};
