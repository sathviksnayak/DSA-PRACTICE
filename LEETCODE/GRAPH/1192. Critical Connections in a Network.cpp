class Solution {
public:
vector<int> disc,low;
 vector<vector<int>> result;
 int timer=0;

 void dfs(int node,int parent,vector<vector<int>>& graph){
    disc[node] = low[node] = timer++;

    for(int nei:graph[node]){
        if(nei==parent) continue;
        if(disc[nei]==-1){
            dfs(nei,node,graph);


            low[node]=min(low[node],low[nei]);


            if(low[nei]>disc[node]){
                result.push_back({node,nei});
            }
        }else{
            low[node]=min(low[node],disc[nei]);
        }
    }
 }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> graph(n);
       for(auto& it:con){
            int u =it[0];
            int v =it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
       }
       disc.resize(n,-1);
       low.resize(n,-1);
       dfs(0,-1,graph);
       return result;

    }
};