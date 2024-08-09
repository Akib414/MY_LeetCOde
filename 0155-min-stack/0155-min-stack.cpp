class MinStack {
public:
stack<int>st ;
stack<int>m ;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) m.push(val);
         else if(val<=m.top())
        m.push(val);
        st.push(val);
      
    }
    
    void pop() {
        if(st.top() == m.top()) m.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */