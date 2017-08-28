#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findLeft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !_stack.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* p = _stack.top();
		_stack.pop();
		findLeft(p->right);
		return p->val;
	}

	void findLeft(TreeNode* root) {
		TreeNode* p = root;
		while (p != NULL) {
			_stack.push(p);
			p = p->left;
		}
	}

private:
	stack<TreeNode*> _stack;
};

int main() {

	//		A
	//	B		C
	//D	  E
	//     F


	TreeNode* nodeA = new TreeNode(8);
	TreeNode* nodeB = new TreeNode(5);
	TreeNode* nodeC = new TreeNode(10);
	TreeNode* nodeD = new TreeNode(3);
	TreeNode* nodeE = new TreeNode(6);
	TreeNode* nodeF = new TreeNode(7);

	nodeA->left = nodeB;
	nodeA->right = nodeC;

	nodeB->left = nodeD;
	nodeB->right = nodeE;

	nodeE->right = nodeF;

	BSTIterator bst(nodeA);
	while (bst.hasNext()) {
		cout << bst.next() << endl;
	}

	return 0;
}
