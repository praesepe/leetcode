class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *result = NULL;
		ListNode *cursor = NULL;
		int sum = 0;

		while (l1 != NULL || l2 != NULL || sum > 0) {
			sum += l1 == NULL ? 0 : l1->val;
			sum += l2 == NULL ? 0 : l2->val;

			if (cursor) {
				cursor->next = new ListNode(sum%10);
				cursor = cursor->next;
			} else {
				cursor = new ListNode(sum%10);
				result = cursor;
			}

			sum = sum / 10;
			l1  = l1 ? l1->next : NULL;
			l2  = l2 ? l2->next : NULL;
		}
		return result;
    }
};
