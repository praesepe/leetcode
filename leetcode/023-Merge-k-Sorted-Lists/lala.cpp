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
	int which;

	HeapNode(ListNode* n, int w) : node(n), which(w) {}
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
		vector<ListNode*> ptr(lists.size());
		for (size_t i = 0; i < lists.size(); i++) {
			ptr[i] = lists[i];
			if (ptr[i]) {
				pq.push(HeapNode(ptr[i], i));
				ptr[i] = ptr[i]->next;
			}
		}

		// run
		while (!pq.empty()) {
			HeapNode h = pq.top();
			walker->next = h.node;
			walker = walker->next;

			if (ptr[h.which]) {
				pq.push(HeapNode(ptr[h.which], h.which));
				ptr[h.which] = ptr[h.which]->next;
			}
			pq.pop();
		}

		return dummy->next;
	}
};
