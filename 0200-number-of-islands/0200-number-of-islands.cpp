class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int nr = row + dir[i].first;
                            int nc = col + dir[i].second;
                            if(nr>=0 && nc >=0 && nr<n && nc<m && grid[nr][nc]=='1'){
                                grid[nr][nc]='0';
                                q.push({nr,nc});
                            } 
                        }
                    }
                }
            }
        }
        return count;
    }
};
// class Solution {
// public:
//     void dfs(vector<vector<char>>& arr, int row, int col, int n,int m, vector<vector<bool>>&vis){
//         if(row<0 || col < 0 || row>=n || col >= m || vis[row][col]){
//             return;
//         }
//         vis[row][col] = true;
//         vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
//         for(int i=0;i<4;i++){
//             int nr = row + dir[i].first;
//             int nc = col + dir[i].second;
//             if(nr>=0 && nc>=0 && nr<n && nc<m && (arr[nr][nc]=='1')){
//                 dfs(arr,nr,nc,n,m,vis);
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int n =grid.size();
//         int m = grid[0].size();

//         vector<vector<bool>>vis(n,vector<bool>(m,false));
//         int result=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='1' && !vis[i][j]){
//                     dfs(grid,i,j,n,m,vis);
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };