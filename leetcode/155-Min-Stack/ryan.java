public class MinStack {

    int min = Integer.MAX_VALUE;
    Stack<Integer> stack = new Stack();

    public void push(int x) {
        if (x <= min) {
            // push current min if x <= min
            stack.push(min);
            // set new min
            min = x;
        }
        stack.push(x);
    }

    public void pop() {
        if (stack.pop() == min) {
            // pop and set next min if pop() == min
            min = stack.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min;
    }
}
