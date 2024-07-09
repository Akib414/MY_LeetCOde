class MyQueue {
public:
    stack<int>mn;
    stack<int>cp;
    int l = 0;
    MyQueue() {
    }


    void push(int x) {
     mn.push(x);
    }
    int pop() {
          stack<int>st = mn;
        while(!cp.empty()) cp.pop();
        while(!st.empty()){
            cp.push(st.top());
            st.pop();
        }
         for(int i = 1 ; i<=l ;i++) cp.pop();
        int x = cp.top();
        cp.pop();
        l++;
        return x;
    }
    
    int peek() {
               stack<int>st = mn;
        while(!cp.empty()) cp.pop();
        while(!st.empty()){
            cp.push(st.top());
            st.pop();
        }
         for(int i = 1 ; i<=l ;i++) cp.pop();
        int x = cp.top();
          return x;
    }
    
    bool empty() {
                   stack<int>st = mn;
        while(!cp.empty()) cp.pop();
        while(!st.empty()){
            cp.push(st.top());
            st.pop();
        }
         for(int i = 1 ; i<=l ;i++) cp.pop();
       
          return cp.empty();
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