class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode *p = head;

        RandomListNode dummy(0);
        RandomListNode *q = &dummy;

        map<RandomListNode*, RandomListNode*> mp;

        // copy each node
        while (p != NULL) {
            q->next = new RandomListNode(p->label);
            mp[p] = q->next;
            p = p->next;
            q = q->next;
        }

        // deal with random pointer
        p = head;
        q = &dummy;
        while (p != NULL) {
            q->next->random = mp[p->random];
            p = p->next;
            q = q->next;
        }

        return dummy.next;
    }
};
