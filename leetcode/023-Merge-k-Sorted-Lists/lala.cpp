#include <stdio.h>
#include <queue>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct HeapNode {
    ListNode* node;

    HeapNode(ListNode* n) : node(n) {}
};

bool operator < (const HeapNode &h1, const HeapNode &h2) {
    return h2.node->val < h1.node->val;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> lists) {
		priority_queue<HeapNode> pq;
		ListNode *dummy = new ListNode(0), *walker = dummy;

		// initilize
		for (size_t i = 0; i < lists.size(); i++) {
			if (lists[i]) {
				pq.push(HeapNode(lists[i]));
			}
		}

		// run
		while (!pq.empty()) {
			HeapNode h = pq.top();
			walker->next = h.node;
			walker = walker->next;
			pq.pop();
			if (h.node->next) {
				pq.push(HeapNode(h.node->next));
			}
		}

		return dummy->next;
	}
};
