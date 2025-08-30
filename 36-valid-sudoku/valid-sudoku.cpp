class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool block[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int d = c - '1'; // map '1' → 0, '2' → 1, ..., '9' → 8
                int b = (i / 3) * 3 + (j / 3); // block index [0..8]

                // If digit already present → invalid
                if (row[i][d] || col[j][d] || block[b][d]) 
                    return false;

                // Mark digit as present
                row[i][d] = col[j][d] = block[b][d] = true;
            }
        }
        return true;
    }
};
