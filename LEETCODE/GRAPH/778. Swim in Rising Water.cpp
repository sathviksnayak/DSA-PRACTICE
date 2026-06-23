class Solution {
public:
    int bfs(vector<vector<int>>& grid){
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({grid[0][0],0,0});
        grid[0][0]=INT_MAX;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            vector<int> cur=q.top();
            q.pop();
            int l=cur[0];
            int i=cur[1],j=cur[2];
            if(i==n-1 && j==n-1){
                return l;
            }
            for(auto& it:dir){
                int di=i+it[0],dj=j+it[1];

                if(di>=0 && di<n && dj>=0 && dj<n && grid[di][dj]!=INT_MAX){
                    q.push({max(l,grid[di][dj]),di,dj});
                    grid[di][dj]=INT_MAX;
                }
            }
            
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};