class Solution {
public:
    void dfs(vector<vector<int>>& arr, int row, int col, int n, int m, vector<vector<bool>>& vis,int height){
        if(row<0 || col <0 || row>n-1 || col> m-1){
            return ;
        }
        if(vis[row][col]){
            return;
        }
        if(height > arr[row][col]){
            return;
        }
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i = 0;i<4;i++){
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            // if(nc>=0 && nr >=0 && nc<m && nr<n && !vis[nr][nc]&& (arr[row][col]<=arr[nr][nc])){
                vis[row][col] = true;
                dfs(arr,nr,nc,n,m,vis,arr[row][col]);
            // }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific( n,vector<bool>(m,false)); // yeh jaha tak pahuch sakte nadi se pac
        vector<vector<bool>> atlantic(n,vector<bool>(m,false)); // aur yahan jahan se mil sakte atlantic

        for(int i = 0 ; i<n;i++){
            dfs(heights , i , 0 , n , m , pacific , heights[i][0]);
            dfs(heights , i , m-1 , n , m , atlantic , heights[i][m-1]);
        }
        for(int i = 0 ; i<m ; i++){
            dfs(heights , 0 , i , n , m , pacific , heights[0][i]);
            dfs(heights , n-1 , i , n , m , atlantic , heights[n-1][i]);
        }
        vector<vector<int>>result;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
// class Solution {
// public:
//     void dfs(vector<vector<int>>& arr, int row, int col, int n, int m, bool &pacific, bool &atlantic,vector<vector<int>>& vis) {
//         if(row<0 || col<0 || row>=n || col >=m || (pacific && atlantic)){
//             return;
//         }
//         if (row == n-1||col == m-1){
//             atlantic = true;
//         }
//         if(row == 0||col==0){
//             pacific = true;
//         }
//         vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, { 0, -1 }};
//         vis[row][col] = 1;
//         for (int i = 0; i < 4; i++) {
//             int nr = row + dir[i].first;
//             int nc = col + dir[i].second;
//             if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
//                 if(arr[row][col]>= arr[nr][nc]){
//                     dfs(arr,nr,nc,n,m,pacific,atlantic,vis);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();
//         vector<vector<int>>result;
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 vector<vector<int>>vis(n,vector<int>(m,0));
//                 bool pacific = false;
//                 bool atlantic = false;
//                 dfs(heights,i,j,n,m,pacific,atlantic,vis);
//                 if(pacific && atlantic){
//                     result.push_back({i,j});
//                 }
//             }
//         }
//         return result;
//     }
// };