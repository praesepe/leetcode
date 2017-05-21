class Solution {
protected:
	ListNode *list;

	int size(ListNode* head) {
		int size = 0;
		while(head) {
			head = head->next;
			size++;
		}
		return size;
	}

	TreeNode* getBST(int size) {
		if (0 == size) {
			return NULL;
		}

		TreeNode *root = new TreeNode(0);
		int half = size / 2;

		root->left  = getBST(half);
		root->val   = list->val;
		list        = list->next;
		root->right = getBST(size-half-1);

		return root;
	}
public:
    TreeNode* sortedListToBST(ListNode* head) {
		this->list = head;
		return getBST(this->size(head));
    }
};
