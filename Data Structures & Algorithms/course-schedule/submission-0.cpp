class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> incoming(n), result;
        vector<int> adj[n];
        for (int i = 0; i < pre.size(); i++) {
            int course = pre[i][0];
            int prerequisite = pre[i][1];
            adj[prerequisite].push_back(course);
        }
        for (int i = 0; i < n; i++)
            for (auto& it : adj[i]) {
                incoming[it]++;
            }
        for (int i = 0; i < n; i++) {
            if (incoming[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto& it : adj[node]) {
                incoming[it]--;
                if (incoming[it] == 0) q.push(it);
            }
        }
        return result.size() == n;
    }
};
