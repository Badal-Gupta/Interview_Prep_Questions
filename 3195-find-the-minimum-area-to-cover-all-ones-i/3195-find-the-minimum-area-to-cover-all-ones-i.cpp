class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int rowmin = n;
        int colmin = m;
        int rowmax = 0;
        int colmax = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(i>rowmax){
                        rowmax = i;
                    }
                    if(j>colmax){
                        colmax = j;
                    }
                    if(i<rowmin){
                        rowmin = i;
                    }
                    if(j<colmin){
                        colmin = j;
                    }
                }
            }
        }
        return ((rowmax - rowmin)+1) * ((colmax - colmin)+1);
    }
};