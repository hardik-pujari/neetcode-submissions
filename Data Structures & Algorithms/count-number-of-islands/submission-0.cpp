class Solution {
   public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    vis[i][j] = 1;
                    q.push({i, {j, ans}});
                }
                while (!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    int r = top.first;
                    int c = top.second.first;
                    int island = top.second.second;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] &&
                            grid[nr][nc] == '1') {
                            vis[nr][nc] = 1;
                            q.push({nr, {nc, ans}});
                        }
                    }
                }
            }
        }
        return ans;
    }
};