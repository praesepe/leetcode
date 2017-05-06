class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }

        // first iteration: clone and insert nodes
        RandomListNode *current;
        for (current = head; current != NULL; current = current->next->next) {
            RandomListNode *newNode = new RandomListNode(current->label);
            newNode->next = current->next;
            current->next = newNode;
        }

        // second iteration: copy random links
        for (current=head; current != NULL; current=current->next->next){
            if (current->random) {
                current->next->random = current->random->next;
            }
        }

        // third iteration: detach the clone list
        RandomListNode *newHead, *newCurrent;
        newHead = head->next;
        for (current=head; current!=NULL; current=current->next) {
            newCurrent = current->next;
            current->next = newCurrent->next;
            if (current->next) {
                newCurrent->next = newCurrent->next->next;
            }
        }

        return newHead;
    }
};
