class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        vector<vector<int>> dp(obs.size(),vector<int>(obs[0].size()));
        if(obs[0][0]==1) return 0;
        dp[0][0]=1;

        for(int i=0;i<obs.size();i++){
            for(int j=0;j<obs[0].size();j++){
                if(obs[i][j]==1) continue;
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
                if(j-1>=0) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[obs.size()-1][obs[0].size()-1];
    }
};