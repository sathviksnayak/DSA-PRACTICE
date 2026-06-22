class Solution {
public:
vector<int> dij(vector<vector<int>>& adj, int s) {
    
    vector<int> dist(adj.size(), INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {

        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (int i = 0; i < adj.size(); i++) {

            if (adj[node][i] != INT_MAX) {

                if (d + adj[node][i] < dist[i]) {
                    dist[i] = d + adj[node][i];
                    pq.push({dist[i], i});
                }
            }
        }
    }

    return dist;
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(auto& it:times){
            adj[it[0]-1][it[1]-1]=it[2];
        }
        vector<int> d=dij(adj,k-1);
        int total=0;
        for(int a:d){
            if(a==INT_MAX){
                return -1;
            }
            total=max(total,a);
        }
        return total;
    }
};