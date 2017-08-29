class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            _stack.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger curr = _stack.top();
        _stack.pop();
        return curr.getInteger();
    }

    bool hasNext() {
        bool result = false;
        while (!_stack.empty()) {
            NestedInteger curr = _stack.top();

            // integer node
            if (curr.isInteger()) {
                return true;
                break;
            }

            // list node
            _stack.pop();
            vector<NestedInteger> list = curr.getList();
            for (int i = list.size() - 1; i >= 0; i--) {
                _stack.push(list[i]);
            }
        }
        return result;
    }

private:
    stack<NestedInteger> _stack;
};

