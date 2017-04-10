#include <stdio.h>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode* dummy = new RandomListNode(0), *walker = dummy;

		//
		unordered_map<RandomListNode*, RandomListNode*> um;
		for (RandomListNode* p = head; p != NULL; p = p->next) {
			walker->next = new RandomListNode(p->label);
			walker = walker->next;
			um.insert(make_pair(p, walker));
		}

		// link random
		walker = dummy->next;
		for (RandomListNode* p = head; p != NULL; p = p->next) {
			walker->random = p->random ? um.find(p->random)->second : NULL;
			walker = walker->next;
		}

		return dummy->next;
	}
};
