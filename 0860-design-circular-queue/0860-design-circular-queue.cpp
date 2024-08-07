class MyCircularQueue {
public:
vector<int>v;
int size;
int first ;
int n;
    MyCircularQueue(int k) {
     v = vector<int>(k,0);
     first = 0;
     size = 0;
     n = v.size();
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        v[(first+size)%n] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        first = (first+1)%n;
        size--;
        return true;
    }
    
    int Front() {
          if(isEmpty()) return -1;
          return v[first];
    }
    
    int Rear() {
          if(isEmpty()) return -1;
          return v[(first+size-1)%n];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */