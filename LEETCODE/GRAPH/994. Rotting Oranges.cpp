class Solution {
public:
int n,m;
int bfs(vector<vector<int>>& grid,int numo,vector<pair<int,int>>& ror){
    int maxr=numo;
    queue<pair<int,int>> q;
    int timer=0;
    for(pair<int,int> x:ror){
        q.push(x);
    }

    while( !q.empty() && numo ){
        int nor=q.size();
        for(int k=0;k<nor;k++){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i-1>=0 && grid[i-1][j]==1 ){
                grid[i-1][j]=2;
                q.push({i-1,j});
                numo--;
                
            }
            if(i+1<n && grid[i+1][j]==1  ){
                grid[i+1][j]=2;
                q.push({i+1,j});
                numo--;
                
            }
            if(j-1>=0 && grid[i][j-1]==1 ){
                grid[i][j-1]=2;
                q.push({i,j-1});
                numo--;
                
            }
            if(j+1<m && grid[i][j+1]==1 ){
                grid[i][j+1]=2;
                q.push({i,j+1});
               numo--;
            }
        }
        timer++;
    }
    if(!numo) return timer;
    return -1;

}
    int orangesRotting(vector<vector<int>>& grid) {
        int numo=0;
        vector<pair<int,int>> ror;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(grid[i][j]==1) numo++;
            else if(grid[i][j]==2) {
                ror.push_back({i,j});
            }
          }
        }
        if(!numo) return 0;
        if(!ror.size()) return -1;
        

        return bfs(grid,numo,ror);
    }
};