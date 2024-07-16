class MyCircularDeque {
public:
vector<int>v;
int size = 0;
int first = 0;
int rear = -1;
int n;
    MyCircularDeque(int k) {
      v = vector<int>(k,0);
      n = k;
    }
    
    bool insertFront(int value) {
        if(size==n) return false;
        if(--first < 0) first = n-1;
        v[first] = value;
        size++;
        if(size == 1) rear = first;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==n) return false;
        if(++rear == n) rear = 0;
        v[rear] = value ;
        size++;
        if(size==1) first = rear;
        return true;
    }
    
    bool deleteFront() {
       if(size==0) return false;
       if(++first==n) first = 0;
       size--;
       return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
          if(--rear<0) rear = n-1;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return v[first];
    }
    
    int getRear() {
         if(size==0) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
