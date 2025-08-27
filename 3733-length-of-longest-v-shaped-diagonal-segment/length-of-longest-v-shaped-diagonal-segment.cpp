// class Solution {
// public:
//     int bfs(int row,int col, int count ,vector<vector<int>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>>visited(n,(vector<bool>(m,false)));
//         queue<pair<int,int>>q;
//         visited[row][col]=true;
//         q.push({row,col});
//         while(!q.empty()){
//             auto [r,c] = q.front();
//             q.pop();
//             count++;
//             vector<pair<int,int>>dir = {{1,1},{-1,-1},{1,-1},{-1,1}};
//             for(auto pairs : dir){
//                 int nr = r + pairs.first;
//                 int nc = c + pairs.second;
//                 if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
//                     if(grid[r][c] == 1 && grid[nr][nc]== 2){
//                         visited[nr][nc] = true;
//                         q.push({nr,nc}); 
//                     }else if (grid[r][c]==2 && grid[nr][nc]==0){
//                         visited[nr][nc]=true;
//                         q.push({nr,nc});
//                     }else if(grid[r][c]==0 && grid[nr][nc]==2){
//                         visited[nr][nc]=true;
//                         q.push({nr,nc});
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// int dfs()
//     int lenOfVDiagonal(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int result = 0;
//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(grid[i][j]==1){
//                     // int temp = bfs(i,j,0,grid);
//                     int temp = dfs(i,j,0,grid);
//                     if(result<temp){
//                         result = temp;
//                     }
//                 }
//             }
//         }
//         return result;     
//     }
// };
class Solution {
public:
    int dr[4] = {-1, 1, 1, -1};
    int dc[4] = {1, 1, -1, -1};

    bool inBounds(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int dir, bool canChange, int len, int searchFor) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = len;
        
        if (dir != -1) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (inBounds(nr, nc, n, m) && grid[nr][nc] == searchFor) {
                int nextVal = (searchFor == 2) ? 0 : 2;
                maxi = max(maxi, dfs(grid, nr, nc, dir, canChange, len + 1, nextVal));
            }
        }

        if (dir != -1 && canChange) {
            int ndir = (dir + 1) % 4;
            int nr = r + dr[ndir];
            int nc = c + dc[ndir];
            if (inBounds(nr, nc, n, m) && grid[nr][nc] == searchFor) {
                int nextVal = (searchFor == 2) ? 0 : 2;
                maxi = max(maxi, dfs(grid, nr, nc, ndir, false, len + 1, nextVal));
            }
        }

        if (dir == -1) {
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (inBounds(nr, nc, n, m) && grid[nr][nc] == searchFor) {
                    int nextVal = (searchFor == 2) ? 0 : 2;
                    maxi = max(maxi, dfs(grid, nr, nc, i, canChange, len + 1, nextVal));
                }
            }
        }

        return maxi;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, dfs(grid, i, j, -1, true, 1, 2));
                }
            }
        }
        return maxi;
    }
};