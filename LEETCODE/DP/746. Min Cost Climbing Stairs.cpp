class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1) return cost[0];
        int c1=cost[0],cur;
        int c2=cost[1];
        for(int i=2;i<cost.size();i++){
            cur=cost[i]+min(c1,c2);
            c1=c2;
            c2=cur;
        }
    return min(c1,c2); 
    }
};