class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j= i;j<n;j++){
                swap(arr[i][j],arr[j][i]);    
            }
        }
        int x = 0;
        int y = n-1;
        while(x<y){
            for(int i=0;i<n;i++){
                swap(arr[i][x],arr[i][y]);
            }
            x++;
            y--;
        }
    }
};