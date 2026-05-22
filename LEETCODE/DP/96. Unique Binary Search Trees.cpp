class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;


        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                int k=i-j-1;
                dp[i]+=dp[j]*dp[k];
            }


        }
        return dp[n];
    }
};
//1-1,2-2,3-5,4-