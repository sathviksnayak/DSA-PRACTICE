class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> x;
        for(int i=0;i<speed.size();i++){
            x.push_back({position[i],speed[i]});
        }
        sort(x.begin(),x.end(),greater<>());

//
int fleet=0;
double lasttime=0;
        for(int i=0;i<speed.size();i++){
           double time=double(target-x[i].first)/x[i].second;
           if(time>lasttime){
            fleet++;
            lasttime=time;
           }

           
        }
        return fleet;
    }
};