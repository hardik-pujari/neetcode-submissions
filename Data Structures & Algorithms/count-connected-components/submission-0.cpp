class DisjointSet {
   public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_v == ulp_u) return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            ds.unionByRank(u,v);
        }
        unordered_set <int> comp;
        for(int i =0 ; i < n ; i++){
            comp.insert(ds.findUPar(i));
        }
        return comp.size();
    }
};
