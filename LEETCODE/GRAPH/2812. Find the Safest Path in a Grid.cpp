class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}} ;

       vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                }
            }
        }

        vector<vector<int>> safeness(n, vector<int>(n, -1));
        priority_queue<vector<int>> pq; 
        safeness[0][0] = dist[0][0];
        pq.push({dist[0][0], 0 ,0});


        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();

            int sf=curr[0],r=curr[1],c=curr[2];

            if(sf<safeness[r][c]) continue;
            if (r == n - 1 && c == n - 1) return sf;

            for(int i=0;i<4;i++){
                int nr=r+dir[i][0],nc=c+dir[i][1];
                if(nr>=0 && nr<=n-1 && nc>=0 && nc<=n-1){
                    int nsf=min(sf,dist[nr][nc]);
                    if (nsf > safeness[nr][nc]) {
                        safeness[nr][nc] = nsf;
                        pq.push({nsf, nr ,nc});
                    }
                }

            }
        }


return safeness[n-1][n-1];

    }
};