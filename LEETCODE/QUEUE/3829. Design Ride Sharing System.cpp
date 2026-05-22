class RideSharingSystem {
public:
queue<int> r,d;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        r.push(riderId);
    }
    
    void addDriver(int driverId) {
        d.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans(2,-1);
        if(!r.empty() && ! d.empty()){
            
            ans[0]=d.front();
            ans[1]=r.front();
            d.pop();
            r.pop();
            
        }
        return ans;

    }
    
  void cancelRider(int riderId) {
    int size = r.size();
    
    while (size--) {
        int curr = r.front();
        r.pop();
        
        if (curr != riderId) {
            r.push(curr);
        }
    }
}
        
    
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */