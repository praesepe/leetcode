#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.a
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int getListLength(ListNode* head) {
		int result = 0;
		while (head) {
			head = head->next;
			result++;
		}

		return result;
	}

	TreeNode* createTree(ListNode*& head, int left, int right) {
		if (right < left) {
			return NULL;
		}

		int mid = (right + left) / 2;


		TreeNode* leftTree = this->createTree(head, left, mid - 1);
		TreeNode* root = new TreeNode(head->val);
		head = head->next;
		TreeNode* rightTree = this->createTree(head, mid + 1, right);

		root->left = leftTree;
		root->right = rightTree;
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int length = this->getListLength(head);

		return this->createTree(head, 0, length - 1);
	}
};
