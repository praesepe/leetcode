#include <stack>

using namespace std;
class MyQueue {
private:
	int get_front() {
		if (this->_fifo.empty()) {
			while (!_filo.empty()) {
				this->_fifo.push(this->_filo.top());
				this->_filo.pop();
			}
		}

		return this->_fifo.top();
	}
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (this->_filo.empty()) {
			this->_front = x;
		}

		this->_filo.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int result = this->get_front();
		this->_fifo.pop();

		return result;
	}

	/** Get the front element. */
	int peek() {
		return this->_fifo.empty() ? this->_front : this->_fifo.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return this->_filo.empty() && this->_fifo.empty();
	}
private:
	int _front;
	stack<int> _filo;
	stack<int> _fifo;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
