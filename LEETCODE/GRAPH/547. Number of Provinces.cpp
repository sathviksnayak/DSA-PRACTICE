class Solution {
public:
void dfs(vector<vector<int>>& is,vector<int>& vis,int s){
    vis[s]=1;
    for(int i=0;i<is[s].size();i++){
        if(is[s][i] && !vis[i]){
            dfs(is,vis,i);
        }
    }
}
    int findCircleNum(vector<vector<int>>& is) {
        vector<int> vis(is.size(),0);
        int ans=0;
        for(int i=0;i<is.size();i++){
            if(!vis[i]){
                dfs(is,vis,i);
                ans++;
            }
        }
        return ans;
    }
};