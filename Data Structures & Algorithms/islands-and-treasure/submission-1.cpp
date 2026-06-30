class Solution {
   public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {-1, 1, 0, 0};
    int inf = pow(2, 31) - 1;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({{i, j}, 0});
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            int r = node.first.first;
            int c = node.first.second;
            int d = node.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == inf)
                {
                    grid[nr][nc] = d + 1;
                    q.push({{nr,nc}, grid[nr][nc]});
                }
            }
        }
    }
};