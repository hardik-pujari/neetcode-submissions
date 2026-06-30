class Solution {
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {-1, 1, 0, 0};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0, fresh= 0, r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {q.push({{i, j}, 0});}
                else if(grid[i][j] == 1) fresh++;
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

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr, nc}, d+1});
                }
            }
            ans = d;
        }
        return (fresh == 0)? ans:-1;
    }
};
