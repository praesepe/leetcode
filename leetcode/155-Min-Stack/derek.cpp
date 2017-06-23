class MinStack {
public:
    stack<int> main_stack;
    stack<int> min_stack;

    MinStack() {

    }

    void push(int x) {
        main_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (main_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        main_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
