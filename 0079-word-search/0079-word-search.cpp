class Solution {
public:
    bool dfs(int row, int col, int n, int m, int ind, string& word, int size,
             vector<vector<char>>& board, vector<vector<bool>>& vis) {

        if (ind == size) {
            return true;
        }

        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] || board[row][col] != word[ind]) {
            return false;
        }

        vis[row][col] = true;

        bool found = dfs(row + 1, col, n, m, ind + 1, word, size, board, vis) ||
                     dfs(row - 1, col, n, m, ind + 1, word, size, board, vis) ||
                     dfs(row, col + 1, n, m, ind + 1, word, size, board, vis) ||
                     dfs(row, col - 1, n, m, ind + 1, word, size, board, vis);

        vis[row][col] = false; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int size = word.size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, n, m, 0, word, size, board, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
