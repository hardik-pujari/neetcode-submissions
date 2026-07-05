class Solution {
public:
    vector<int> rd = {0, 0, -1, 1};
    vector<int> cd = {-1, 1, 0, 0};
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {
        if (idx == word.size())
            return true;
        int n = board.size();
        int m = board[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m)
            return false;
        if (board[r][c] != word[idx])
            return false;
        char temp = board[r][c];
        board[r][c] = '#';      // mark visited
        for (int i = 0; i < 4; i++) {
            int nr = r + rd[i];
            int nc = c + cd[i];
            if (dfs(board, word, nr, nc, idx + 1))
                return true;
        }
        board[r][c] = temp;     // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};