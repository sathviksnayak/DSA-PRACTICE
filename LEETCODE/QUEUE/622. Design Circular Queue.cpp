class MyCircularQueue {
public:
vector<int> q;
int f=0,r=0;
int n;
int size=0;
    MyCircularQueue(int k) {
        q.resize(k);
        n=k;
    }
    
    bool enQueue(int value) {
       if(size==n) return false;
        q[(r++)%n]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;
         f++;
        size--;
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return q[f%n];
    }
    
    int Rear() {
        if(size==0) return -1;
        return q[(r-1)%n];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==n;
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