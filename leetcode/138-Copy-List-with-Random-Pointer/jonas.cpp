class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> hash;
		RandomListNode *result, *curOld, *curResult;

		if (!head) {
			return NULL;
		}

		// Copy list without random, create node hash mappping
		result = new RandomListNode(head->label);

		for (curOld = head, curResult = result; curOld; curOld = curOld->next, curResult = curResult->next) {
			hash[curOld] = curResult;
			curResult->next = curOld->next ? new RandomListNode(curOld->next->label) : NULL;
		}

		// Add random to copied list
		for (curOld = head, curResult = result; curOld; curOld = curOld->next, curResult = curResult->next) {
			curResult->random = hash[curOld->random];
		}

		return result;
    }
};
