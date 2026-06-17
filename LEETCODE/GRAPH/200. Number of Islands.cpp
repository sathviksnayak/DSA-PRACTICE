class Solution {
public:
int n,m;
void bfs(vector<int>& visited,vector<vector<char>>& grid,int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        i=p.first;
        j=p.second;
        if(visited[i*m+j]) continue;
        if(i-1>=0 && grid[i-1][j]=='1' ) q.push({i-1,j});
        if(i+1<n && grid[i+1][j]=='1') q.push({i+1,j});
        if(j-1>=0 && grid[i][j-1]=='1') q.push({i,j-1});
        if(j+1<m && grid[i][j+1]=='1') q.push({i,j+1});
        visited[m*i+j]=1;
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n=grid.size(),m=grid[0].size();
        vector<int> visited(n*m);
        for(int i=0;i<m*n;i++){
            int r=i/m;
            int c=i%m;
            if(!visited[i] && grid[r][c]=='1' ){
            ans++;
            bfs(visited,grid,r,c);

            }
        }
        return ans;
    }
};