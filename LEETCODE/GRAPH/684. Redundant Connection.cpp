class Solution {
public:
vector<int> parent,rank;


    int find(int x){
        if(parent[x]==x){
            return x;
        }
         return find(parent[x]);
    }

    bool unite(int x,int y){
        int rx=find(x),ry=find(y);

        if (rx == ry) return false;
         if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;

         return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;

        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            if(!unite(u,v)){
                return edge;
            }
        
        } 
        return {};
    }
};