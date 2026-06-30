class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1) return triangle[0][0];
        int mind=INT_MAX;
        for(int i=1;i<n;i++){
            int m=triangle[i].size();
            for(int j=0;j<m;j++){
                int left=INT_MAX,right=INT_MAX;

                if(j-1>=0)  left=triangle[i-1][j-1];
                if(j<triangle[i-1].size()) right=triangle[i-1][j];

                triangle[i][j]+=min(left,right);
                if(i==n-1){
                    mind=min(mind,triangle[i][j]);
                }
                
            }
        }
        return mind;
    }
};