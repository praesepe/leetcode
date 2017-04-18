#include <stdio.h>

struct Node {
	int val;
	int min;
	Node* next;

	Node(int v, int m) : val(v), min(m) {};
};

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		this->_stack = NULL;
	}

	~MinStack() {
		Node *p = this->_stack, *tmp = NULL;
		while (p) {
			tmp = p->next;
			delete p;
			p = tmp;
		}
	}

	void push(int val) {
		int min = this->getMin() > val ? val : this->getMin();

		Node* n = new Node(val, min);
		n->next = this->_stack;

		this->_stack = n;
	}

	void pop() {
		Node* tmp = this->_stack;
		if (!tmp) {
			return;
		}

		tmp = this->_stack->next;
		delete this->_stack;
		this->_stack = tmp;
	}

	int top() {
		Node* t = this->_stack;
		return t ? t->val : 0;
	}

	int getMin() {
		Node* t = this->_stack;
		return t ? t->min : INT_MAX;
	}
private:
	Node* _stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
