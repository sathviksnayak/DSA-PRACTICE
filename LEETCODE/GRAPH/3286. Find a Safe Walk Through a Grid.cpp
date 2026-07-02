class Solution {
public:
bool bfs(vector<vector<int>>& grid,int hp){
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<vector<int>> q;
    q.push({hp-grid[0][0],0,0});
    visited[0][0]=hp-grid[0][0];
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        vector<int> curr=q.front();q.pop();
        int chp=curr[0],i=curr[1],j=curr[2];

        for(int k=0;k<4;k++){
            int ci=i+dir[k][0],cj=j+dir[k][1];
            if(ci>=0 && ci<n && cj>=0 && cj<m && (chp-grid[ci][cj])>visited[ci][cj]){
                q.push({chp-grid[ci][cj],ci,cj});
                visited[ci][cj]=chp-grid[ci][cj];
            }
        }
    }
    return visited[n-1][m-1];

}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       return bfs(grid,health); 
    }
};