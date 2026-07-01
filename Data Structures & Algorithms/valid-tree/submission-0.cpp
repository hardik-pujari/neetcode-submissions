class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        queue<pair<int, int>> q;

        q.push({0, -1});
        vis[0] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != parent) {
                    return false;
                }
            }
        }

        for (int x : vis)
            if (!x) return false;

        return true;
    }
};