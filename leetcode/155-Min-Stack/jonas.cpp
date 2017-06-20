class MinStack {
protected:
	long min = INT_MAX;
	stack<long> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
		this->s.push(x - this->min);
		this->min = x < this->min ? x : this->min;
    }

    void pop() {
		if (0 > this->s.top()) {
			this->min = this->min - this->s.top();
		}
		this->s.pop();
    }

    int top() {
		if (0 > this->s.top()) {
			return this->min;
		} else {
			return this->min + this->s.top();
		}
    }

    int getMin() {
        return this->min;
    }
};
