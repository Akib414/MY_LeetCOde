class MyStack {
public:
     queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
   
    int pop() {
          queue<int>cp;
      int x;
      while(!q.empty()){
        x = q.front();
        q.pop();
        if(!q.empty()) cp.push(x);
      }
      q = cp;
      return x;
    }   
    int top() {
         queue<int>cp;
          int x;
      while(!q.empty()){
        x = q.front();
        q.pop();
       cp.push(x);
      }
      q = cp;
      return x;
    }   
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */