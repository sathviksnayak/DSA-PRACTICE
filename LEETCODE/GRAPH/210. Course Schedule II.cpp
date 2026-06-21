class Solution {
public:
bool cdfs(int x,vector<vector<int>>& graph ,vector<int>& state){
   state[x]=1;
    for(int nei : graph[x]){

        if(state[nei]==1)
            return false;   

        if(state[nei]==0){
            if(!cdfs(nei,graph,state))
                return false;
        }
    }

   state[x]=2;
   return true;

}
    void dfs(int s,vector<int>& vis,vector<vector<int>>& graph,stack<int>& st){
        vis[s]=1;


        for(int nei:graph[s]){
            if(!vis[nei]){
                dfs(nei,vis,graph,st);
            }

        }

        st.push(s);
    }
    vector<int> toposort(vector<vector<int>>& graph,int n){
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph,st);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        for(auto& it:pre){
            graph[it[1]].push_back(it[0]);
        }
        bool pos=true;
        vector<int> state(n,0);
        for(int i=0;i<graph.size();i++){
            if(state[i]==0){
                if(!cdfs(i,graph,state)) {
                    pos=false;
                    break;
                }
            }
        }
        if(pos)
        return toposort(graph,n);
        return {};
    }
};