class Solution {
public:
    vector<int> color;
    
    bool dfs(int u,vector<vector<int>>& graph){
        if(color[u]==1) return false;
        else if(color[u]==2) return true;

        color[u]=1;
        for(int nei:graph[u]){
            if(!dfs(nei,graph)){
                return false;
            }

        }

        color[u]=2;
        return true;

    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        color.resize(graph.size());
        for(int i=0;i<graph.size();i++){
            if(dfs(i,graph)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};