class Solution {
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};

    void dfs(vector<vector<char>>& board,
             vector<vector<int>>& vis,
             vector<vector<int>>& mark,
             int r, int c,
             int m, int n) {

        vis[r][c] = 1;
        mark[r][c] = -1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !vis[nr][nc] &&
                board[nr][nc] == 'O') {

                dfs(board, vis, mark, nr, nc, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> mark(m, vector<int>(n, 0));


        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(board, vis, mark, i, 0, m, n);

            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                dfs(board, vis, mark, i, n - 1, m, n);
        }


        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(board, vis, mark, 0, j, m, n);

            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                dfs(board, vis, mark, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && mark[i][j] != -1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};