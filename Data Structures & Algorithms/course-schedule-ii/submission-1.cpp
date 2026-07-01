class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<int> result;
        vector<vector<int>> adj(n);
        for (auto &edge : pre) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
        }
        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (result.size() == n)
            return result;

        return {};
    }
};