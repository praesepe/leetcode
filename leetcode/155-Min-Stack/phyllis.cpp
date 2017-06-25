/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

class MinStack {
private:
    vector<int> stack;
    vector<int> minStack;
    vector<int>::iterator it;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        
        if(minStack.size() == 0){
            minStack.push_back(x);
        }else if(x <= minStack.back()){
            minStack.push_back(x);
        }
    }
    
    void pop() {
        if(minStack.back() == stack.back()){
            minStack.pop_back();
        }
        
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();   
    }
};
