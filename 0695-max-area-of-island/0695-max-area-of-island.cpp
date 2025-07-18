class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        int result= 0;
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    int count = 0;
                    grid[i][j]=0;
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        count++;
                        for(int a = 0 ;a<4;a++){
                            int nr = row + dir[a].first;
                            int nc = col + dir[a].second;
                            if(nc>=0 && nr>=0 && nr<n && nc<m && grid[nr][nc]==1){
                                q.push({nr,nc});
                                grid[nr][nc]=0;
                            }
                        }
                    }
                    result = max(result,count);
                }
            }
        }
        return result;
    }
};
// class Solution {
// public:
//     void dfs(vector<vector<int>>& arr , int row , int col , int n ,int m ,vector<vector<bool>>&vis , int &count){
//         if(row<0 || col < 0 || row>=n || col>=m || arr[row][col]==0 || vis[row][col]){
//             return;
//         }
//         count++;
//         vis[row][col] = true;
//         vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
//         for(int i = 0;i<4;i++){
//             int nr =row+dir[i].first;
//             int nc = col + dir[i].second;
//             dfs(arr,nr,nc,n,m,vis,count);
//         }
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<bool>>vis(n,vector<bool>(m,false));
//         int result = 0;
//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(grid[i][j]==1 && !vis[i][j]){
//                     int count = 0;
//                     dfs(grid,i,j,n,m,vis,count);
//                     if(count>result){
//                         result = count;
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };