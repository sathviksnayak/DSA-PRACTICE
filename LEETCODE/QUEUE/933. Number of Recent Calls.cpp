class RecentCounter {
public:
queue<int> a;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!a.empty()&& a.front()<t-3000){
            a.pop();
        }
        a.push(t);
        return a.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */