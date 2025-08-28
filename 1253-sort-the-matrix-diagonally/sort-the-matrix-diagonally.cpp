class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1||m==1){
            return grid;
        }
        for(int i=0; i<n;i++){
            int x = i;
            int y = 0;
            vector<int>temp;
            while(x<n && y<m){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=i;
            y=0;
            while(x<n && y<m){
                grid[x][y] = temp[y];
                x++;
                y++;
            }
        }
        for(int j=1; j<m;j++){
            int x = 0;
            int y = j;
            vector<int>temp;
            while(y<m && x<n){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=0;
            y=j;
            while(y<m && x<n){
                grid[x][y] = temp[x];
                x++;
                y++;
            }
        }
        return grid;
    }
};