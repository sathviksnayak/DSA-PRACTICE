class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1,0});
        res.push_back({n,n-1});
        sort(res.begin(),res.end());
        for(int i=1;i<res.size();i++){
            int d=res[i][0]-res[i-1][0];
            res[i][1]=min(res[i][1],res[i-1][1]+d);
        }
        for(int i=res.size()-2;i>=0;i--){
            int d=res[i+1][0]-res[i][0];
            res[i][1]=min(res[i][1],res[i+1][1]+d);
        }
        int ans=0;
        for(int i=1;i<res.size();i++){
            int peak=((res[i][0]-res[i-1][0])+res[i-1][1]+res[i][1])/2;
            ans=max(ans,peak);
        }
        return ans;

        

    }
};