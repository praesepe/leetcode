class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            if (a && b) {
                return a->val > b->val;
            }
            return a == NULL;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)>
            queue(cmp, lists);
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while (!queue.empty()) {
            tail->next = queue.top();
            queue.pop();

            if (!tail->next) {
                continue;
            }
            tail = tail->next;
            if (tail->next) {
                queue.push(tail->next);
            }
        }

        ListNode *result = head->next;
        delete head;
        return result;
    }
};
