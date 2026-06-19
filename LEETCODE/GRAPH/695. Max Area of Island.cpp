class Solution {
public:
int n,m;
    int bfs(vector<vector<int>>& grid,vector<int>& visited,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i*m+j]=1;
        int area=1;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            i=p.first;
            j=p.second;
            if(i-1>=0 && grid[i-1][j]==1 && !visited[(i-1)*m+j]){
                q.push({i-1,j});
                visited[(i-1)*m+j]=1;
                area++;
            }
            if(i+1<n && grid[i+1][j]==1 && !visited[(i+1)*m+j]){
                q.push({i+1,j});
                visited[(i+1)*m+j]=1;
                area++;
            }
            if(j-1>=0 && grid[i][j-1]==1 && !visited[(i)*m+(j-1)]){
                q.push({i,j-1});
                visited[(i)*m+(j-1)]=1;
                area++;
            }
            if(j+1<m && grid[i][j+1]==1 && !visited[(i)*m+(j+1)]){
                q.push({i,j+1});
                visited[(i)*m+(j+1)]=1;
                area++;
            }
            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n=grid.size(),m=grid[0].size();
        vector<int> visited(m*n);
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&& !visited[i*m+j]){
                    ans=max(ans,bfs(grid,visited,i,j));
                }
            }
        }
        return ans;
    }
};