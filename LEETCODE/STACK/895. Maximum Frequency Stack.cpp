

class FreqStack {
public:
    int i=0;
    unordered_map<int,int> map;
    set<pair<pair<int,int>,int>> s;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        
        map[val]++;
        s.insert({{map[val],i++},val});
    }
    
    int pop() {
        
        auto it = prev(s.end());  
        auto val = *it;

        int a=val.second;
        map[a]--;
        s.erase(it);
        return a;
        }
        
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */