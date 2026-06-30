class Solution {
    vector<int> dc = {-1,1,0,0};
    vector<int> dr = {0,0,-1,1};
   public:
    void dfs(vector<vector<int>>& heights, int n, int m, int r, int c, vector<vector<int>>& sea, 
             vector<vector<int>>& vis) {
        vis[r][c] = 1;
        sea[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, n, m, nr, nc, sea, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(heights, n, m, i, 0, pacific, vis);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, n, m, 0, j, pacific, vis);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) vis[i][j] = 0;
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, n, m, i, m - 1, atlantic, vis);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, n, m, n - 1, j, atlantic, vis);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};