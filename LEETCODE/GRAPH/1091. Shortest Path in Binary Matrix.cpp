class Solution {
public:

    int bfs(vector<vector<int>>& grid){

        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;

        queue<vector<int>> q;
        q.push({0,0,1});

        grid[0][0]=1;   

        vector<vector<int>> dir = {
            {1,0},{0,1},{-1,0},{0,-1},
            {1,1},{-1,-1},{1,-1},{-1,1}
        };

        while(!q.empty()){

            vector<int> cur = q.front();
            q.pop();

            int i = cur[0];
            int j = cur[1];
            int l = cur[2];

            if(i==n-1 && j==n-1)
                return l;

            for(auto& d : dir){

                int di = i + d[0];
                int dj = j + d[1];

                if(di>=0 && di<n &&
                   dj>=0 && dj<n &&
                   grid[di][dj]==0){

                    grid[di][dj]=1;      
                    q.push({di,dj,l+1});
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};