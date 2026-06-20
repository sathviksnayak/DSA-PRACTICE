class Solution {
public:
bool dfs(int x,vector<vector<int>>& graph ,vector<int>& state){
   state[x]=1;
    for(int nei : graph[x]){

        if(state[nei]==1)
            return false;   

        if(state[nei]==0){
            if(!dfs(nei,graph,state))
                return false;
        }
    }

   state[x]=2;
   return true;

}
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> state(n,0);
        vector<vector<int>> graph(n);
            for(auto& it: pre){
            graph[it[1]].push_back(it[0]);
}
        for(int i=0;i<graph.size();i++){
            if(state[i]==0){
                if(!dfs(i,graph,state)) return false;
            }
        }

return true;
    }
};