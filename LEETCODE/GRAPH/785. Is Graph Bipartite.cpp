class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph,vector<int>& colors){
        queue<int> q;
        q.push(start);
        colors[start]=1;
        while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int n:graph[cur]){
            if(colors[n]==-1){
                colors[n]=1-colors[cur];
                q.push(n);
            }
            else if(colors[n]==colors[cur]){
                return false;
            }
        }
        }
    return true;
        }
    
    bool isBipartite(vector<vector<int>>& graph) {
      vector<int> colors(graph.size(),-1);  
      
      for(int i=0;i<graph.size();i++){
        if(colors[i]==-1)
            if(!bfs(i,graph,colors)) return false;
      }
      return true;
    }
};