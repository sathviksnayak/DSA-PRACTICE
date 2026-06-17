class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;

        for(int x:adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto &it:edges){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
        }
        dfs(source,adj,vis);

        return vis[destination]==1;
    }
};