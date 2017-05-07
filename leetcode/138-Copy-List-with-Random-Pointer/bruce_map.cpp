#include <unordered_map>

using namespace std;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        // clone nodes and create unordered_map
        RandomListNode *current;
        unordered_map<RandomListNode *, RandomListNode *> map;
        for (current = head; current != NULL; current = current->next) {
            map.insert(make_pair(current, new RandomListNode(current->label)));
        }

        // add next and random pointers to new nodes
        for (current = head; current != NULL; current = current->next) {
            if (current->next) {
                map.find(current)->second->next = map.find(current->next)->second;
            }

            if (current->random) {
                map.find(current)->second->random = map.find(current->random)->second;
            }
        }

        return map.find(head)->second;
    }
};
