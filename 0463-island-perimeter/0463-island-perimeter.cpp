class Solution {
public:
    void check(vector<vector<int>>& arr, int row, int col, int n, int m, int &parameter){
        int count  = 4;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0;i<4;i++){
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if( nc>=0 && nr>=0 && nr<n && nc<m && arr[nr][nc]==1){
                count--;
            }
        }
        parameter = parameter + count;
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int parameter = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    check(grid,i,j,n,m,parameter);
                }
            }
        }
        return parameter;
    }
};