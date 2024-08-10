class MyQueue {
public:
    stack<int>st ;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
            stack<int>cp;
        int x;
        while(!st.empty()){
             x = st.top();
            st.pop();
            if(!st.empty()) cp.push(x);
        }
          while(!cp.empty()){
            st.push(cp.top());
            cp.pop();
          }
        return x ;
    }
    
    int peek() {
        stack<int>cp = st ;
        int x ;
        while(!cp.empty()){
            x = cp.top();
            cp.pop();
        }
        return x ;
        
    }
    
    bool empty() {
       return st.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */