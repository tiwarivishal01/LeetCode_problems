class MinStack {
private:
    stack<int> minstack;
    stack<int> st;

public:
    MinStack() {}

    void push(int value) {

        if (minstack.empty()) {
            minstack.push(value);
        } else {
            int mini = min(minstack.top(), value);
            minstack.push(mini);
        }

        st.push(value);
    }

    void pop() {
        st.pop();
        minstack.pop();
    }

    int top() {
        int val = st.top();
        return val;
    }

    int getMin() { return minstack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */