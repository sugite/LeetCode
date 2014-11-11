class MinStack {
public:
    void push(int x) {
        if(stk.empty() || x<=minStk.top())
            minStk.push(x);
        stk.push(x);
    }

    void pop() {
        if(stk.empty()) return ;
        if(stk.top()==minStk.top())
            minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();    
    }
    
private:
    stack<int> stk;
    stack<int> minStk;
};
