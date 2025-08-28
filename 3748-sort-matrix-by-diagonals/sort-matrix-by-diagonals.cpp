class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n;i++){
            int x = i;
            int y = 0;
            vector<int>temp;
            while(x<n){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=i;
            int z = y-1;
            y=0;
            while(x<n){
                grid[x][y] = temp[z];
                x++;
                y++;
                z--;
            }
        }
        for(int j=1; j<n;j++){
            int x = 0;
            int y = j;
            vector<int>temp;
            while(y<n){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=0;
            y=j;
            while(y<n){
                grid[x][y] = temp[x];
                x++;
                y++;
            }
        }
        return grid;
    }
};